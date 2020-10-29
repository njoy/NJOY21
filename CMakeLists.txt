########################################################################
# Preamble
########################################################################

cmake_minimum_required( VERSION 3.14 )
project( njoy21 LANGUAGES CXX )


########################################################################
# Project-wide setup
########################################################################

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED YES )

#TODO Unit tests disabled until build system is fixed.
option( njoy21_unit_tests
    "Compile the njoy21 unit tests and integrate with ctest" OFF
    )
option( strict_compile
    "Treat all warnings as errors." ON
    )

# Compile flags
set( common_flags "-Wall" "-Wextra" "-Wpedantic" )
set( strict_flags "-Werror" )
set( release_flags "-O3" )
set( debug_flags "-O0" "-g" )


########################################################################
# Dependencies
########################################################################

set( REPOSITORIES "release"
    CACHE STRING
    "Options for where to fetch repositories: develop, release, local"
    )

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

configure_file( "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/Signature.hpp.in"
                "${CMAKE_CURRENT_BINARY_DIR}/src/njoy21/Signature.hpp" @ONLY )

add_executable( njoy21
    src/main.cpp
    )
target_include_directories( njoy21
    PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/src/
    src/
    )
target_link_libraries( njoy21
    PUBLIC ENDFtk
    PUBLIC dimwits
    PUBLIC lipservice
    PUBLIC njoy_c_bindings
    PUBLIC tclap-adapter
    PUBLIC utility
    )
target_compile_options( njoy21 PRIVATE
    ${common_flags}
    $<$<BOOL:${strict_compile}>:${strict_flags}>
    $<$<CONFIG:DEBUG>:${debug_flags}>
    $<$<CONFIG:RELEASE>:${release_flags}>
    )


#######################################################################
# Top-level Only
#######################################################################

if( CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR )

    # unit testing
    if( njoy21_unit_tests )
        include( cmake/unit_testing.cmake )
    endif()

    # integral testing
    message( STATUS "Adding integral testing" )
    enable_testing()
    add_subdirectory( tests )

endif()
