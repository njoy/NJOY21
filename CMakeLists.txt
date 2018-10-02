
cmake_minimum_required( VERSION 3.2 )
set( CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Supported configuration types" FORCE )
        
if ( NOT GIT_EXECUTABLE )
    find_package( Git 2.1 )
    if ( NOT GIT_FOUND )
        message( FATAL_ERROR "git installation was not found." )
    endif()
endif()

if( NOT ROOT_DIRECTORY )
    set( ROOT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )
    if ( NOT fetched_subprojects )
        if ( NOT PYTHON_EXECUTABLE )
            find_package( PythonInterp 3.4 )
            if ( NOT PYTHONINTERP_FOUND )
                message( FATAL_ERROR "Python interpeter installation was not found." )
            endif()
        endif()
        execute_process( COMMAND ${PYTHON_EXECUTABLE} "./metaconfigure/fetch_subprojects.py"
                         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                         RESULT_VARIABLE fetch_failure )
        if ( NOT fetch_failure )
            set( fetched_subprojects TRUE CACHE BOOL "fetch script ran" )
        else()
            message( FATAL_ERROR "Failed to fetch dependencies" )
        endif()
    endif()
endif()

if( NOT ROOT_DIRECTORY )
    set( ROOT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )
endif()
if ( NOT PYTHON_EXECUTABLE )
    find_package( PythonInterp )
    if ( NOT PYTHONINTERP_FOUND )
        message( FATAL_ERROR "Python interpeter installation was not found." )
    endif()
endif()
execute_process( COMMAND ${PYTHON_EXECUTABLE} ./metaconfigure/signature.py ${CMAKE_BINARY_DIR}/signature
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE signature_failure )
file( READ "${CMAKE_BINARY_DIR}/signature.json" SIGNATURE )

project( njoy21 LANGUAGES CXX )
get_directory_property( is_subproject PARENT_DIRECTORY )
include( CMakeDependentOption REQUIRED )
enable_language( Fortran )

set( njoy21_AppleClang_minimum_version 8.0 )
set( njoy21_GNU_minimum_version 6.2 )
set( njoy21_Clang_minimum_version 3.8 )

if( njoy21_${CMAKE_CXX_COMPILER_ID}_minimum_version )
    if( CMAKE_CXX_COMPILER_VERSION AND
        CMAKE_CXX_COMPILER_VERSION VERSION_LESS
        ${njoy21_${CMAKE_CXX_COMPILER_ID}_minimum_version} )
        message( FATAL_ERROR "${CMAKE_CXX_COMPILER_ID} version must be greater than ${njoy21_${CMAKE_CXX_COMPILER_ID}_minimum_version}" )
    endif()
endif()

# general properties
option( njoy21_strict "Compile time warnings are converted to errors" ON )

# binary instrumentation
option( coverage "Enable binary instrumentation to collect test coverage information in the DEBUG configuration" )
option( profile_generate "Enable binary instrumentation to generation execution profiles in the RELEASE configuration which may be used to guide later optimization" )

# additional optimizations
option( link_time_optimization "Enable link time optimization in the RELEASE configuration" )
option( profile_use "In the RELEASE configuration, leverage previously generated exeution profile to inform optimization decisions" )
option( nonportable_optimization "Enable optimizations which compromise portability of resulting binary in the RELEASE configuration" )

# libraries and linking
option( static "Statically link component and environment libraries" OFF )
if ( static AND ( "${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin" ) )
    message( FATAL_ERROR "Static binaries not supported on OSX" )
endif()

CMAKE_DEPENDENT_OPTION( static_libraries "Statically link component libraries" OFF "NOT static" ON )
CMAKE_DEPENDENT_OPTION( static_njoy21 "Statically link the njoy21 component library" OFF "NOT static;NOT static_libraries" ON ) 

option( unit_tests "Compile the njoy21 unit tests and integrate with ctest" ON ) 

if ( profile_generate AND profile_use )
    message( FATAL_ERROR "Cannot both generate and use execution profile in the same configuration" )
endif()

if ( profile_generate )
    file( MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/profiling" )
endif()

set( njoy21_AppleClang_Darwin_common_flags "-stdlib=libc++" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( njoy21_AppleClang_Darwin_DEBUG_flags "-O0" "-g" "-gdwarf-3" )
set( njoy21_AppleClang_Darwin_RELEASE_flags "-O3" "-DNDEBUG" )
set( njoy21_AppleClang_Darwin_strict_flags "-Werror" )
set( njoy21_AppleClang_Darwin_coverage_flags "--coverage" )
set( njoy21_AppleClang_Darwin_subproject_flags  )
set( njoy21_AppleClang_Darwin_base_project_flags  )
set( njoy21_AppleClang_Darwin_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_AppleClang_Darwin_link_time_optimization_flags "-flto" )
set( njoy21_AppleClang_Darwin_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_AppleClang_Darwin_nonportable_optimization_flags "-march=native" )
set( njoy21_AppleClang_Darwin_static_flags "-static" )
set( njoy21_GNU_Windows_common_flags "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( njoy21_GNU_Windows_DEBUG_flags "-O0" "-g" "-gdwarf-3" "-fsignaling-nans" )
set( njoy21_GNU_Windows_RELEASE_flags "-O3" "-DNDEBUG" )
set( njoy21_GNU_Windows_strict_flags "-Werror" )
set( njoy21_GNU_Windows_coverage_flags "--coverage" )
set( njoy21_GNU_Windows_subproject_flags  )
set( njoy21_GNU_Windows_base_project_flags  )
set( njoy21_GNU_Windows_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_GNU_Windows_link_time_optimization_flags "-flto" )
set( njoy21_GNU_Windows_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_GNU_Windows_nonportable_optimization_flags "-march=native" )
set( njoy21_GNU_Windows_static_flags "-static" )
set( njoy21_GNU_Linux_common_flags "-Wno-subobject-linkage" "-Wall" "-Wextra" "-Wpedantic" "-Wno-maybe-uninitialized" "-std=c++14" )
set( njoy21_GNU_Linux_DEBUG_flags "-O0" "-g" "-gdwarf-3" "-fsignaling-nans" )
set( njoy21_GNU_Linux_RELEASE_flags "-O3" "-DNDEBUG" )
set( njoy21_GNU_Linux_strict_flags "-Werror" )
set( njoy21_GNU_Linux_coverage_flags "--coverage" )
set( njoy21_GNU_Linux_subproject_flags  )
set( njoy21_GNU_Linux_base_project_flags  )
set( njoy21_GNU_Linux_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_GNU_Linux_link_time_optimization_flags "-flto" )
set( njoy21_GNU_Linux_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_GNU_Linux_nonportable_optimization_flags "-march=native" )
set( njoy21_GNU_Linux_static_flags "-static" )
set( njoy21_GNU_Darwin_common_flags "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( njoy21_GNU_Darwin_DEBUG_flags "-O0" "-g" "-gdwarf-3" "-fsignaling-nans" )
set( njoy21_GNU_Darwin_RELEASE_flags "-O3" "-DNDEBUG" )
set( njoy21_GNU_Darwin_strict_flags "-Werror" )
set( njoy21_GNU_Darwin_coverage_flags "--coverage" )
set( njoy21_GNU_Darwin_subproject_flags  )
set( njoy21_GNU_Darwin_base_project_flags  )
set( njoy21_GNU_Darwin_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_GNU_Darwin_link_time_optimization_flags "-flto" )
set( njoy21_GNU_Darwin_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_GNU_Darwin_nonportable_optimization_flags "-march=native" )
set( njoy21_GNU_Darwin_static_flags "-static" )
set( njoy21_Clang_Windows_common_flags "-stdlib=libc++" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( njoy21_Clang_Windows_DEBUG_flags "-O0" "-g" "-gdwarf-3" )
set( njoy21_Clang_Windows_RELEASE_flags "-O3" "-DNDEBUG" )
set( njoy21_Clang_Windows_strict_flags "-Werror" )
set( njoy21_Clang_Windows_coverage_flags "--coverage" )
set( njoy21_Clang_Windows_subproject_flags  )
set( njoy21_Clang_Windows_base_project_flags  )
set( njoy21_Clang_Windows_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_Clang_Windows_link_time_optimization_flags "-flto" )
set( njoy21_Clang_Windows_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_Clang_Windows_nonportable_optimization_flags "-march=native" )
set( njoy21_Clang_Windows_static_flags "-static" )
set( njoy21_Clang_Linux_common_flags "-stdlib=libstdc++" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( njoy21_Clang_Linux_DEBUG_flags "-O0" "-g" "-gdwarf-3" )
set( njoy21_Clang_Linux_RELEASE_flags "-O3" "-DNDEBUG" )
set( njoy21_Clang_Linux_strict_flags "-Werror" )
set( njoy21_Clang_Linux_coverage_flags "--coverage" )
set( njoy21_Clang_Linux_subproject_flags  )
set( njoy21_Clang_Linux_base_project_flags  )
set( njoy21_Clang_Linux_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_Clang_Linux_link_time_optimization_flags "-flto" )
set( njoy21_Clang_Linux_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_Clang_Linux_nonportable_optimization_flags "-march=native" )
set( njoy21_Clang_Linux_static_flags "-static" )
set( njoy21_Clang_Darwin_common_flags "-stdlib=libc++" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( njoy21_Clang_Darwin_DEBUG_flags "-O0" "-g" "-gdwarf-3" )
set( njoy21_Clang_Darwin_RELEASE_flags "-O3" "-DNDEBUG" )
set( njoy21_Clang_Darwin_strict_flags "-Werror" )
set( njoy21_Clang_Darwin_coverage_flags "--coverage" )
set( njoy21_Clang_Darwin_subproject_flags  )
set( njoy21_Clang_Darwin_base_project_flags  )
set( njoy21_Clang_Darwin_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_Clang_Darwin_link_time_optimization_flags "-flto" )
set( njoy21_Clang_Darwin_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_Clang_Darwin_nonportable_optimization_flags "-march=native" )
set( njoy21_Clang_Darwin_static_flags "-static" )

if ( static_njoy21 )
    set( njoy21_library_linkage STATIC )
else ()
    set( njoy21_library_linkage SHARED )
endif ()

set( CMAKE_SKIP_BUILD_RPATH FALSE )
set( CMAKE_BUILD_WITH_INSTALL_RPATH FALSE )
if ( CMAKE_SYSTEM_NAME STREQUAL "Darwin" )
    set( rpath_prefix "@loader_path" )
else()
    set( rpath_prefix "\\$ORIGIN" )
endif()
list( INSERT 0 CMAKE_INSTALL_RPATH "${rpath_prefix}/../lib" )
set( CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE )
get_directory_property( is_subproject PARENT_DIRECTORY )

if( NOT TARGET catch-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/catch-adapter )
endif()

if( NOT TARGET hana-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/hana-adapter )
endif()

if( NOT TARGET dimwits )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/dimwits )
endif()

if( NOT TARGET disco )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/disco )
endif()

if( NOT TARGET fmt-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/fmt-adapter )
endif()

if( NOT TARGET spdlog-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/spdlog-adapter )
endif()

if( NOT TARGET Log )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/Log )
endif()

if( NOT TARGET header-utilities )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/header-utilities )
endif()

if( NOT TARGET hopscotch-map-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/hopscotch-map-adapter )
endif()

if( NOT TARGET range-v3-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/range-v3-adapter )
endif()

if( NOT TARGET variant-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/variant-adapter )
endif()

if( NOT TARGET ENDFtk )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/ENDFtk )
endif()

if( NOT TARGET utility )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/utility )
endif()

if( NOT TARGET lipservice )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/lipservice )
endif()

if( NOT TARGET njoy )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/njoy )
endif()

if( NOT TARGET njoy_c_bindings )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/njoy_c_bindings )
endif()

if( NOT TARGET tclap-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/tclap-adapter )
endif()


if ( NOT GIT_EXECUTABLE )
    find_package( Git )
    if ( NOT GIT_FOUND )
        message( FATAL_ERROR "git installation was not found." )
    endif()
endif()

execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse --abbrev-ref HEAD
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_BRANCH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
) 

message( STATUS "" )
message( STATUS "-----------------------------------------------------------" )
message( STATUS "" )
message( STATUS "njoy21" )
message( STATUS "Git current branch: ${GIT_BRANCH}" )
message( STATUS "Git commit hash: ${GIT_HASH}" )
message( STATUS "" )
message( STATUS "-----------------------------------------------------------" )

configure_file( "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/Signature.hpp.in"
                "${CMAKE_CURRENT_BINARY_DIR}/src/njoy21/Signature.hpp" )

add_library( njoy21 ${njoy21_library_linkage}
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/banner.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/CommandLine.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/Driver.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/interface.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/io.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/legacy.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/Sequence.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/Version.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/CommandLine/src/ctor.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/Driver/Factory.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/Driver/Factory/src/callOperator.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/Driver/Factory/src/setupLegacyDirectory.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/Driver/Factory/src/setupManager.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/Driver/src/callOperator.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/io/Manager.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/io/Manager/Builder.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/io/Manager/FileGuard.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/io/Manager/Builder/src/construct.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/io/Manager/src/output.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/legacy/Sequence.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/legacy/Sequence/Factory.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/legacy/Sequence/routines.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
             "${CMAKE_CURRENT_BINARY_DIR}/src/njoy21/Signature.hpp" )

target_include_directories( njoy21 PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/src src )

set( PREFIX njoy21_${CMAKE_CXX_COMPILER_ID}_${CMAKE_SYSTEM_NAME} )

target_compile_options( njoy21 PRIVATE 
${${PREFIX}_common_flags}
$<$<BOOL:${njoy21_strict}>:${${PREFIX}_strict_flags}>
$<$<BOOL:${static}>:${${PREFIX}_static_flags}>
$<$<BOOL:${is_subproject}>:${${PREFIX}_subproject_flags}>
$<$<NOT:$<BOOL:${is_subproject}>>:${${PREFIX}_base_project_flags}>
$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags} 
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags} 
$<$<BOOL:${profile_generate}>:${${PREFIX}_profile_generate_flags}> 
$<$<BOOL:${profile_use}>:${${PREFIX}_profile_use_flags}> 
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}> 
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>
${CXX_appended_flags} ${njoy21_appended_flags} )

target_link_libraries( njoy21 PUBLIC "$<$<AND:$<CONFIG:RELEASE>,$<BOOL:${link_time_optimization}>>:${${PREFIX}_RELEASE_flags};${${PREFIX}_link_time_optimization_flags}$<$<BOOL:${profile_generate}>:${${PREFIX}_profile_generate_flags};>$<$<BOOL:${profile_use}>:${${PREFIX}_profile_use_flags};>$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags};>>$<$<CONFIG:DEBUG>:$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags};>>$<$<BOOL:CXX_appended_flags>:${CXX_appended_flags};>$<$<BOOL:njoy21_appended_flags>:${njoy21_appended_flags};>" )

target_link_libraries( njoy21 PUBLIC dimwits PUBLIC ENDFtk PUBLIC lipservice PUBLIC njoy_c_bindings PUBLIC tclap-adapter PUBLIC utility PUBLIC variant-adapter )

if ( NOT is_subproject )
    add_executable( njoy21_executable src/main.cpp )
    set_target_properties( njoy21_executable PROPERTIES OUTPUT_NAME njoy21 )
    target_compile_options( njoy21_executable PRIVATE 
    ${${PREFIX}_common_flags}
    $<$<BOOL:${njoy21_strict}>:${${PREFIX}_strict_flags}>
    $<$<BOOL:${static}>:${${PREFIX}_static_flags}>
    $<$<BOOL:${is_subproject}>:${${PREFIX}_subproject_flags}>
    $<$<NOT:$<BOOL:${is_subproject}>>:${${PREFIX}_base_project_flags}>
    $<$<CONFIG:DEBUG>:
    ${${PREFIX}_DEBUG_flags} 
    $<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
    $<$<CONFIG:RELEASE>:
    ${${PREFIX}_RELEASE_flags} 
    $<$<BOOL:${profile_generate}>:${${PREFIX}_profile_generate_flags}> 
    $<$<BOOL:${profile_use}>:${${PREFIX}_profile_use_flags}> 
    $<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}> 
    $<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>
    ${CXX_appended_flags} ${njoy21_appended_flags} )
    target_link_libraries( njoy21_executable PUBLIC njoy21 )
endif()

if( NOT is_subproject )
    enable_testing() 
    if ( unit_tests )
        add_subdirectory( src/njoy21/CommandLine/test )
        add_subdirectory( src/njoy21/Driver/test )
        add_subdirectory( src/njoy21/io/Manager/test )
        add_subdirectory( src/njoy21/legacy/Sequence/test )
    endif() 
    add_subdirectory( tests )
endif()

set( installation_targets njoy21 )
if ( NOT is_subproject )
    list( APPEND installation_targets njoy21_executable )
endif()

install( TARGETS ${installation_targets}
         RUNTIME DESTINATION bin
         LIBRARY DESTINATION lib
         ARCHIVE DESTINATION lib
         PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                     GROUP_EXECUTE GROUP_READ
                     WORLD_EXECUTE WORLD_READ )

install( DIRECTORY src/ DESTINATION include
         FILE_PERMISSIONS OWNER_READ OWNER_WRITE
                          GROUP_READ
                          WORLD_READ
         DIRECTORY_PERMISSIONS OWNER_READ OWNER_WRITE
                               GROUP_READ
                               WORLD_READ
         FILES_MATCHING REGEX ".*\.h[+][+]$|.*\.hxx$|.*\.hpp$|.*\.hh$|.*\.h$"  )

                    INCLUDE(CPack)
                    