"""
generate cmake files for a project from a serialized project description
"""
import os
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
  name = state['name']
  contents = ''
  if not state['is_external_project']:
    contents += 'if( NOT DEFINED build_type ) \n'
    contents += '  set( build_type "debug" ) \n'
    contents += 'endif() \n\n'
  if not ( state['is_external_project'] and state['type'] == 'include' ):
    contents += 'if( NOT DEFINED ' + name + '_build_type ) \n'
    contents += '  set( ' + name + '_build_type "${build_type}" ) \n'
    contents += 'endif() \n\n'
  return contents

def set_library_type( state ):
  name = state['name']
  contents = ''
  if not state['is_external_project']:
    contents += 'if( NOT DEFINED static_libraries ) \n'
    contents += '  set( build_static_libraries FALSE ) \n'
    contents += 'else() \n'
    contents += '  set( build_static_libraries TRUE ) \n'
    contents += 'endif() \n\n'
  if state['type'] != 'include' :
    contents += 'if( NOT DEFINED static_' + name + ' ) \n'
    contents += '  set( static_' + name + ' ${build_static_libraries} ) \n'
    contents += 'endif() \n\n'
    contents += 'if( ${static_' + name + '} ) \n'
    contents += '  set( ' + name + '_policy STATIC ) \n'
    contents += 'else() \n'
    contents += '  set( ' + name + '_policy SHARED ) \n'
    contents += 'endif() \n\n'
  return contents

def configure_compiler( state ):
  contents = ''
  name = state['name']
  if not ( state['is_external_project'] and ( state['type'] == 'include' ) ):
    language = language_string[ state['language'] ]
    contents += 'if( DEFINED ' + language + '_compiler_flags ) \n'
    contents += '  if( ( NOT DEFINED ' + name + '_compiler_flags ) AND ( NOT DEFINED ' + name + '_use_default_compiler_flags ) ) \n'
    contents += '    set( ' + name + '_compiler_flags "${' + language + '_compiler_flags}" ) \n'
    contents += '  endif() \n'
    contents += 'endif() \n'
    contents += 'if( NOT DEFINED ' + name + '_compiler_flags ) \n'
    contents += '  if( DEFINED no_link_time_optimization ) \n'
    contents += '      set( no_link_time_optimization TRUE ) \n'
    contents += '  endif() \n'
    block = ''
    if ( state['type'] == 'include' ):
      contents += '  if( NOT DEFINED is_subproject ) \n'
      block = '  '
    contents += block + '  '
    for compiler in compilers[ state['language'] ]:
      version_flag = ''
      if 'language_revision' in state:
        version_flag = ' ' + revision_flag( state['language'], state['language_revision'], compiler )
      contents += 'if( CMAKE_' + language + '_COMPILER_ID STREQUAL "' + compiler_string[compiler] + '" ) \n'
      contents += block + '    if( ${' + name + '_build_type} STREQUAL "debug" ) \n'
      contents += block + '      set( ' + name + '_compiler_flags "' + warning_flags[compiler] + ' ' + debug_flags[compiler] + version_flag + '" ) \n'
      contents += block + '    elseif( ${' + name + '_build_type} STREQUAL "coverage" ) \n'
      contents += block + '      set( ' + name + '_compiler_flags "' + warning_flags[compiler] + ' ' + debug_flags[compiler] + ' ' + coverage_flags[compiler] + version_flag +  '" ) \n'
      contents += block + '    elseif( ${' + name + '_build_type} STREQUAL "release" ) \n'
      contents += block + '      set( ' + name + '_compiler_flags "' + warning_flags[compiler] + ' ' + optimization_flags[compiler] + version_flag + '" ) \n'
      contents += block + '      if( NOT DEFINED no_link_time_optimization ) \n'
      contents += block + '        set( ' + name + '_compiler_flags "${' + name + '_compiler_flags} ' + link_time_optimization_flags[compiler] + '" ) \n'
      contents += block + '      endif() \n'
      contents += block + '    elseif( ${' + name + '_build_type} STREQUAL "native" ) \n'
      contents += block + '      set( ' + name + '_compiler_flags "' + warning_flags[compiler] + ' ' + optimization_flags[compiler] + ' ' + native_flags[compiler] + version_flag + '" ) \n'
      contents += block + '      if( NOT DEFINED no_link_time_optimization ) \n'
      contents += block + '        set( ' + name + '_compiler_flags "${' + name + '_compiler_flags} ' + link_time_optimization_flags[compiler] + '" ) \n'
      contents += block + '      endif() \n'
      contents += block + '    endif() \n'
      contents += block + '  else'
    contents += '() \n'
    contents += block + '    message( WARNING "Compiler vendor not recognized. No compilation flags set" ) \n'
    contents += block + '  endif() \n'
    contents += block + 'endif() \n'
    contents += block + 'if( DEFINED appended_flags AND NOT ' + name + '_no_appended_flags ) \n'
    contents += block + '  set( ' + name + '_compiler_flags "${' + name + '_compiler_flags} ${appended_flags}" ) \n'
    contents += block + 'endif() \n'
    contents += block + 'if( DEFINED ' + name + '_appended_flags ) \n'
    contents += block + '  set( ' + name + '_compiler_flags "${' + name + '_compiler_flags} ${' + name + '_appended_flags}" ) \n'
    contents += block + 'endif() \n'
    if ( state['type'] == 'include' ):
      contents += 'endif() \n'
    contents += '\n'
  return contents
  
def project_statement( state ):
  name = state['name']
  version = state['version']
  language = language_string[ state['language'] ]
  contents = 'project( ' + name  + ' VERSION ' + version + ' LANGUAGES ' + language + ' )\n\n'
  return contents

def traverse_subprojects( state ):
  contents = ''
  if state['subprojects'] and not state['is_external_project']:
    contents += 'if( NOT DEFINED is_subproject ) \n'
    contents += '  set( is_subproject ) \n'
    build_queue = description.reconstruct_build_queue( state )
    build_queue.pop()
    for subproject in build_queue:
      contents += '  add_subdirectory( subprojects/' + subproject + ' ) \n'
    contents += '  unset( is_subproject ) \n'
    contents += 'endif() \n\n'
  return contents

def collect_revision_info( state ):
  name = state['name']
  contents = ''
  contents += 'execute_process( \n'
  contents += '  COMMAND git rev-parse --abbrev-ref HEAD \n'
  contents += '  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} \n'
  contents += '  OUTPUT_VARIABLE GIT_BRANCH \n'
  contents += '  OUTPUT_STRIP_TRAILING_WHITESPACE \n'
  contents += ') \n'
  contents += 'execute_process( \n'
  contents += '  COMMAND git rev-parse HEAD \n'
  contents += '  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} \n'
  contents += '  OUTPUT_VARIABLE GIT_HASH \n'
  contents += '  OUTPUT_STRIP_TRAILING_WHITESPACE \n'
  contents += ') \n\n'
  return contents

def print_banner( state ):
  name = state['name']
  version = state['version']
  contents = ''
  contents += 'message( STATUS "" ) \n'
  contents += 'message( STATUS "-----------------------------------------------------------" ) \n'
  contents += 'message( STATUS "" ) \n'
  contents += 'message( STATUS "' + name + ' Version: ' + version + '" ) \n'
  contents += 'message( STATUS "Git current branch: ${GIT_BRANCH}" ) \n'
  contents += 'message( STATUS "Git commit hash: ${GIT_HASH}" ) \n'
  contents += 'message( STATUS "" ) \n'
  if not ( state['is_external_project'] and ( state['type'] == 'include' ) ):
    block = ''
    if state['type'] == 'include' :
      contents += 'if( NOT DEFINED is_subproject ) \n'
      block = '  '
    contents += block + 'message( STATUS "' + name + ' flags: ${' + name + '_compiler_flags}" ) \n'
    contents += block + 'message( STATUS "" ) \n'
    if ( state['type'] == 'include' ):
      contents += 'endif() \n'
  contents += 'message( STATUS "-----------------------------------------------------------" ) \n'
  contents += 'message( STATUS "" ) \n\n'
  return contents

def add_targets( state ):
  contents = ""
  name = state['name']
  implementation_files = state['implementation_files']
  sources = '\n'.join( implementation_files )
  language = language_string[ state['language'] ]
  if state['type'] == 'executable' :
    driver = state['driver']
    contents += 'add_library( ' + name + ' ${' + name + '_policy} \n' + sources + ' ) \n'
    contents += 'target_compile_options( ' + name + ' ${' + name + '_compiler_flags} ) \n'
    if state['language'] == 'fortran':
      contents += 'target_include_directories( ' + name + ' PUBLIC ${PROJECT_BINARY_DIRECTORY} ) \n'
    if 'include_path' in state and state['include_path']:
      contents += 'target_include_directories( ' + name + ' PUBLIC ' + state['include_path'] + ' ) \n\n'
      contents += 'include_directories( ' + state['include_path'] + ' ) \n'
    else:
      contents += '\n'
    contents += 'CMAKE_' + language + '_FLAGS( ${' + name + '_compiler_flags} ) \n'
    contents += 'add_executable( ' + name +  '_executable ' + driver + ' ) \n'
    contents += 'set_target_properties( ' + name + '_executable PROPERTIES OUTPUT_NAME ' + name + ' ) \n'
    contents += 'target_link_libraries( ' + name + '_executable PUBLIC ' + name + ' ) \n'
  elif state['type'] == 'library' :
    contents += 'add_library( ' + name + ' ${' + name + '_policy} \n' +  sources + ' ) \n'
    if state['language'] == 'fortran':
      contents += 'target_include_directories( ' + name + ' PUBLIC ${PROJECT_BINARY_DIRECTORY} ) \n'
    contents += 'target_compile_options( ' + name + ' ${' + name + '_compiler_flags} ) \n'
    if 'include_path' in state and state['include_path']:
      contents += 'target_include_directories( ' + name + ' PUBLIC ' + state['include_path'] + ' ) \n'
  elif state['type'] == 'include' :
    contents += 'add_library( ' + name + ' INTERFACE ) \n'
    if 'include_path' in state and state['include_path']:
      contents += 'target_include_directories( ' + name + ' INTERFACE ' + state['include_path'] + ' ) \n'
  else :
    raise RuntimeError('Unrecognized target type')
  return contents

def link_dependencies( state ):
  contents = ''
  name = state['name']
  if len( state['subprojects'] ) > 0 :
    contents += 'target_link_libraries( ' + name
    for name, subproject in state['subprojects'].items():
      if state['type'] == 'include':
        contents += ' INTERFACE ' + name
      else:
        contents += ' PUBLIC ' + name
    contents += ' ) \n'
  contents += '\n'
  return contents

def add_unit_tests( state ):
  contents = ''
  if not state['is_external_project'] and state['unit_tests']:
    name = state['name']
    contents += 'if( NOT DEFINED is_subproject ) \n'
    contents += '  enable_testing() \n'
    for test_name, sources in state['unit_tests'].items():
      executable_name = test_name + '.test'
      directory = os.path.split( sources[0] ) [0]
      contents += '  add_subdirectory( ' + directory + ' ) \n'
      test_contents = ''
      test_contents += 'add_executable( ' + executable_name 
      if len(sources) > 1:
        split = '\n                '
      else:
        split = ' '
      test_contents += split + split.join( [ os.path.split( entry )[1] for entry in sources ] ) + ' ) \n'
      test_contents += 'set( test_flags ${' + name + '_compiler_flags} ) \n'
      test_contents += 'separate_arguments( test_flags ) \n'
      test_contents += 'foreach( flag IN LISTS test_flags ) \n '
      test_contents += '  target_compile_options( ' + executable_name + ' PUBLIC ${flag} ) \n'
      test_contents += 'endforeach( flag ) \n'
      test_contents += 'target_link_libraries( ' + executable_name + ' PUBLIC ' + name + ' ) \n'
      if os.path.isdir( os.path.join( directory, 'resources' ) ):
           test_contents += 'file( GLOB resources "resources/*" ) \n'
           test_contents += 'file( COPY "${resources}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}" ) \n'
      test_contents += 'add_test( NAME ' + test_name + ' COMMAND ' + executable_name + ' ) \n'
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
