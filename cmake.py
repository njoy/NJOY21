"""
generate cmake files for a project from a serialized project description
"""
import os
import textwrap
import description
from compiler_configuration import *

language_string = { 'c' : 'C', 'c++' : 'CXX', 'fortran' : 'Fortran' }
compiler_string = { 'gcc' : 'GNU',
                    'g++' : 'GNU',
                    'gfortran' : 'GNU',
                    'clang' : 'Clang',
                    'clang++' : 'Clang',
                    'apple clang' : 'AppleClang',
                    'apple clang++' : 'AppleClang' }

def set_build_type( state ):
  contents = ''
  if not state['is_external_project']:
      contents += textwrap.dedent("""
         if( NOT DEFINED build_type )
             set ( build_type "debug" )
         endif()
      """)
      if state['type'] == 'include':
          contents += textwrap.dedent("""
              if( NOT DEFINED {name}_build_type )
                  set( {name}_build_type "${{build_type}}" )
              endif()
              """.format(**state))
  return contents

def set_library_type( state ):
    contents = ''
    if not state['is_external_project']:
        contents += textwrap.dedent( """
            if( NOT DEFINED static_libraries )
                set( build_static_libraries FALSE )
            else()
                set( build_static_libraries TRUE )
            endif()
            """)
    if state['type'] != 'include' :

        contents += textwrap.dedent( """
            if( NOT DEFINED static_{name} )
                set( static_{name} ${{build_static_libraries}} )
            endif()

            if( ${{static_{name}}} )
                set( {name}_policy STATIC )
            else()
                set( {name}_policy SHARED )
            endif()
            """.format(**state))
    return contents

def configure_compiler( state ):
    contents = ''
    name = state['name']
    if not ( state['is_external_project'] and ( state['type'] == 'include' ) ):
        language_s = language_string[ state['language'] ]
        contents += textwrap.dedent( """
            if( DEFINED {language_s}_compiler_flags )
                if( ( NOT DEFINED {name}_compiler_flags ) AND ( NOT DEFINED {name}_use_default_compiler_flags ) )
                    set( {name}_compiler_flags "${{{language_s}_compiler_flags}}" )
                endif()
            endif()
            if( NOT DEFINED {name}_compiler_flags )
                if( DEFINED no_link_time_optimization )
                    set( no_link_time_optimization TRUE )
                endif()
            """.format(**state, language_s=language))
        block = ''
        if ( state['type'] == 'include' ):
            contents += '  if( NOT DEFINED is_subproject ) \n'
            block = '    '

        contents += block + '    '
        for compiler in compilers[ state['language'] ]:
            version_flag = ''
            if 'language_revision' in state:
              version_flag = ' ' + revision_flag( state['language'], state['language_revision'], compiler )

            contents += textwrap.dedent( """    {block}if( CMAKE_{language}_COMPILER_ID STREQUAL "{compiler_string}" )
            {block}if( ${{{name}_build_type}} STREQUAL "debug" )
            {block}    set( {name}_compiler_flags "{warning_flags} {debug_flags} {version_flag}" )
            {block}elseif( ${{{name}_build_type}} STREQUAL "coverage" )
            {block}    set( {name}_compiler_flags "{warning_flags} {debug_flags} {coverage_flags} {version_flag}" )
            {block}elseif( ${{{name}_build_type}} STREQUAL "release" )
            {block}    set( {name}_compiler_flags "{warning_flags} {optimization_flags} {version_flag}" )
            {block}    if( NOT DEFINED no_link_time_optimization )
            {block}        set( {name}_compiler_flags "${{{name}_compiler_flags}} {link_time_optimization_flags}" )
            {block}    endif()
            {block}elseif( ${{{name}_build_type}} STREQUAL "native" )
            {block}    set( {name}_compiler_flags "{warning_flags} {optimization_flags} {native_flags} {version_flag}" )
            {block}    if( NOT DEFINED no_link_time_optimization )
            {block}        set( {name}_compiler_flags "${{{name}_compiler_flags}} {link_time_optimization_flags}" )
            {block}    endif()
            {block}endif()
            """).format(name=state['name'], language=language,
                         compiler_string=compiler_string[compiler],
                         warning_flags=warning_flags[compiler],
                         debug_flags=debug_flags[compiler],
                         optimization_flags=optimization_flags[compiler],
                         link_time_optimization_flags=link_time_optimization_flags[compiler],
                         version_flag=version_flag,
                         native_flags=native_flags[compiler],
                         coverage_flags=coverage_flags[compiler],
                         block=block
                         )
            contents+="    {block}else".format(block=block)
        contents += '()'
        contents += textwrap.dedent("""
          {block}        message( WARNING "Compiler vendor not recognized. No compilation flags set" )
          {block}    endif()
          {block}endif()
          {block}if( DEFINED appended_flags AND NOT {name}_no_appended_flags )
          {block}    set( {name}_compiler_flags "${{{name}_compiler_flags}} ${{appended_flags}}" )
          {block}endif()
          {block}if( DEFINED {name}_appended_flags )
          {block}    set( {name}_compiler_flags "${{{name}_compiler_flags}} ${{{name}_appended_flags}}" )
          {block}endif()""".format(**state, block=block))
        if ( state['type'] == 'include' ):
          contents += 'endif() \n'
        contents += '\n'
    return contents

def project_statement( state ):
    language = language_string[ state['language'] ]
    contents = 'project( {name} VERSION {version} LANGUAGES {language_s} )\n'.format(**state, language_s=language)
    return contents

def traverse_subprojects( state ):
    contents = ''
    if state['subprojects'] and not state['is_external_project']:
        contents += 'if( NOT DEFINED is_subproject )\n  set( is_subproject )'
        build_queue = description.reconstruct_build_queue( state )
        build_queue.pop()
        for subproject in build_queue:
            contents += '  add_subdirectory( subprojects/{subproject})'.format(subproject)
        contents += '  unset( is_subproject )\nendif()'
    return contents

def collect_revision_info( state ):
  return textwrap.dedent("""
    execute_process(
        COMMAND git rev-parse --abbrev-ref HEAD
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_BRANCH
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    execute_process(
        COMMAND git rev-parse HEAD
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    """)

def print_banner( state ):
    contents = textwrap.dedent("""
        message( STATUS "" )
        message( STATUS "-----------------------------------------------------------" )
        message( STATUS "" )
        message( STATUS "{name} Version: {version}" )
        message( STATUS "Git current branch: ${{GIT_BRANCH}}" )
        message( STATUS "Git commit hash: ${{GIT_HASH}}" )
        message( STATUS "" )
        """.format(**state))
    if not ( state['is_external_project'] and ( state['type'] == 'include' ) ):
        block = ''
        if state['type'] == 'include' :
            contents += 'if( NOT DEFINED is_subproject ) \n'
            block = '    '
        contents += '{}message( STATUS "{name} flags: ${{{name}_compiler_flags}}" ) \n'.format(block, **state)
        contents += '{}message( STATUS "" ) \n'.format(block)
        if ( state['type'] == 'include' ):
            contents += 'endif() \n'
    contents += 'message( STATUS "-----------------------------------------------------------" ) \n'
    contents += 'message( STATUS "" ) \n\n'
    return contents

def add_targets( state ):
    contents = ""
    sources = '\n'.join( state['implementation_files'] )
    language_s = language_string[ state['language'] ]

    if state['type'] == 'executable' :
        contents += textwrap.dedent("""add_library( {name} ${{{name}_policy}}
                    {sources} )

                    target_compile_options( {name} ${{{name}_compiler_flags}} )
            """.format(**state, sources=sources))

        if state['language'] == 'fortran':
            contents += 'target_include_directories( {name} PUBLIC ${{PROJECT_BINARY_DIRECTORY}} ) \n'.format(**state)

        if 'include_path' in state and state['include_path']:
            contents += texwrap.dedent("""target_include_directories( {name} PUBLIC {include_path} )

                            include_directories( {include_path} )
                            """.format(**state))
        else:
            contents += textwrap.dedent("""
                CMAKE_{language_s}_FLAGS( ${{{name}_compiler_flags}} )
                add_executable( {name}_executable {driver} )
                set_target_properties( {name}_executable PROPERTIES OUTPUT_NAME {name} )
                target_link_libraries( {name}_executable PUBLIC {name} )
                """.format(**state, language_s=language_s))
    elif state['type'] == 'library' :
        contents += 'add_library( {name} ${{{name}_policy}} \n{sources}\n'.format(**state, sources=sources)
        if state['language'] == 'fortran':
            contents += 'target_include_directories( {name} PUBLIC ${{PROJECT_BINARY_DIRECTORY}}\n'.format(**state)

        contents += 'target_compile_options( {name} ${{{name}_compiler_flags}} )'.format(**state)
        if 'include_path' in state and state['include_path']:
            contents += 'target_include_directories( {name} PUBLIC {include_path} )'.format(**state)
    elif state['type'] == 'include' :
        contents += 'add_library( {name} INTERFACE )'.format(**state)
        if 'include_path' in state and state['include_path']:
            contents += 'target_include_directories( {name} INTERFACE {include_path} )'.format(**state)
    else :
        raise RuntimeError('Unrecognized target type: {}'.format(state['type']))
    return contents

def link_dependencies( state ):
  contents = ''
  name = state['name']
  if len( state['subprojects'] ) > 0 :
    contents += 'target_link_libraries( {}'.format(name)
    for name, subproject in state['subprojects'].items():
      if state['type'] == 'include':
        contents += ' INTERFACE {}'.format(name)
      else:
        contents += ' PUBLIC {}'.format(name)
    contents += ' ) \n'
  contents += '\n'
  return contents

def add_unit_tests( state ):
    contents = ''
    if not state['is_external_project'] and state['unit_tests']:
        name = state['name']
        contents += 'if( NOT DEFINED is_subproject ) \n  enable_testing() \n'
        for test_name, sources in state['unit_tests'].items():
            executable_name = test_name + '.test'
            directory = os.path.split( sources[0] )[0]
            contents += '  add_subdirectory( {} ) \n'.format(directory)
            test_contents = 'add_executable( {}'.format(executable_name)

            if len(sources) > 1:
                split = '\n                '
            else:
                split = ' '
            test_contents += split + split.join( [ os.path.split( entry )[1] for entry in sources ] ) + ' )'
            test_contents += textwrap.dedent("""
                set( test_flags ${{{name}_compiler_flags}} )
                separate_arguments( test_flags )
                foreach( flag IN LISTS test_flags ) \n '
                  target_compile_options( {executable_name} PUBLIC ${{flag}} )
                endforeach( flag )
                target_link_libraries( {executable_name} PUBLIC {name} )
            """.format(name=name, executable_name=executable_name))
            if os.path.isdir( os.path.join( directory, 'resources' ) ):
                test_contents += 'file( GLOB resources "resources/*" ) \n'
                test_contents += 'file( COPY "${{resources}}" DESTINATION "${{CMAKE_CURRENT_BINARY_DIR}}" ) \n'
            test_contents += 'add_test( NAME {} COMMAND {} ) \n'.format(test_name, executable_name)
            with open( os.path.join( directory, 'CMakeLists.txt' ), 'w') as TestCMakeFile:
                TestCMakeFile.write( test_contents )
        contents += 'endif() \n'
    return contents

def generate():
  state = description.deserialize()
  description.collect_subprojects( state )
  contents = "cmake_minimum_required( VERSION 3.2 ) \n\n"
  contents += set_build_type( state )
  contents += set_library_type( state )
  contents += project_statement( state )
  contents += traverse_subprojects( state )
  contents += collect_revision_info( state )
  contents += configure_compiler( state )
  contents += print_banner( state )
  contents += add_targets( state )
  contents += link_dependencies( state )
  contents += add_unit_tests( state )
  with open('CMakeLists.txt', 'w') as CMakeFile:
    CMakeFile.write(contents)


if __name__ == "__main__":
    print("\nI'm running cmake.")

    state = { 'name' : "NJOY21",
            'version' : "1.0.0",
            'type' : "library",
            'language' : "c++",
            'header_files' : [],
            'implementation_files' : [],
            'unit_tests' : {},
            'subprojects' : {},
            'project_path' : os.getcwd(),
            'is_external_project' : False }
#   print(set_library_type(state))
#   print(add_targets(state))
#   print(configure_compiler(state))
#   print(project_statement(state))
#   print(traverse_subprojects(state))
#   print(collect_revision_info(state))
#   print(print_banner(state))
#   print(add_targets(state))
#   print(link_dependencies(state))
#   print(add_unit_tests(state))

    print("I'm done")
