########################################################################
# Preamble
########################################################################

cmake_minimum_required( VERSION 3.14 )
project( njoy21 LANGUAGES CXX )
enable_language( Fortran )

########################################################################
# Project-wide setup
########################################################################

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED YES )

option( njoy21_unit_tests
    "Compile the njoy21 unit tests and integrate with ctest" ON
    )
option( strict_compile
    "Treat all warnings as errors." ON
    )

# Compile flags
set( common_flags "-Wall" "-Wextra" "-Wpedantic" )
set( strict_flags "-Werror" "-Wno-unknown-warning-option" )
set( release_flags "-O3" )
set( debug_flags "-O0" "-g" )


########################################################################
# Dependencies
########################################################################

set( REPOSITORIES "develop"
    CACHE STRING
    "Options for where to fetch repositories: develop, release, local"
    )

message( STATUS "Using ${REPOSITORIES} repositories" )

if( REPOSITORIES STREQUAL "develop" )
    include( cmake/develop_dependencies.cmake )

elseif( REPOSITORIES STREQUAL "release" )
    include( cmake/release_dependencies.cmake )

elseif( REPOSITORIES STREQUAL "local" )
    include( cmake/local_dependencies.cmake )

endif()


########################################################################
# Project targets
########################################################################

add_library( njoy21_library INTERFACE
    )
target_include_directories( njoy21_library
    INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/src/
    src/
    )
target_link_libraries( njoy21_library
    INTERFACE leapr
    INTERFACE ENDFtk
    INTERFACE dimwits
    INTERFACE lipservice
    INTERFACE njoy_c_bindings
    INTERFACE tclap-adapter
    INTERFACE utility
    INTERFACE nlohmann_json
    )

#######################################################################
# Top-level Only
#######################################################################

if( CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR )

    add_executable( njoy21
        src/main.cpp
        )
    target_link_libraries( njoy21
        PUBLIC njoy21_library
        )
    target_compile_options( njoy21 PRIVATE
        ${common_flags}
        $<$<BOOL:${strict_compile}>:${strict_flags}>
        $<$<CONFIG:DEBUG>:${debug_flags}>
        $<$<CONFIG:RELEASE>:${release_flags}>
        )

    # unit testing
    if( njoy21_unit_tests )
        include( cmake/unit_testing.cmake )
    endif()

    # integral testing
    message( STATUS "Adding integral testing" )
    enable_testing()
    add_subdirectory( tests )

endif()
