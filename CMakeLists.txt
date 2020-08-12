#######################################################################
# Preamble
#######################################################################

cmake_minimum_required( VERSION 3.16 )
project( NJOY21 LANGUAGES CXX )
enable_language( Fortran )


#######################################################################
# Project-wide setup
#######################################################################

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED YES )

option( unit_tests
    "Compile the njoy21 unit tests and integrate with ctest" ON
    )


#######################################################################
# Dependencies
#######################################################################

set( DEPENDENCY_REPOS "live"
    CACHE STRING
    "Options for where to fetch repositories: live, signature, local"
    )

if( DEPENDENCY_REPOS STREQUAL "live" )
    include( cmake/live_dependencies.cmake )

elseif( DEPENDENCY_REPOS STREQUAL "signature" )
    include( cmake/signature_dependencies.cmake )

elseif( DEPENDENCY_REPOS STREQUAL "local" )
    include( cmake/local_dependencies.cmake )

endif()


#######################################################################
# Main project targets
#######################################################################

configure_file( "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/Signature.hpp.in"
                "${CMAKE_CURRENT_BINARY_DIR}/src/njoy21/Signature.hpp" @ONLY )


#######################################################################
# Top-level Only
#######################################################################

if( CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR )

    # add NJOY21 executable
    message( STATUS "Adding executable" )
    add_executable( njoy21 src/main.cpp )
    target_include_directories( njoy21 
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/src/
              src/
        )

    set_target_properties( njoy21
                           PROPERTIES OUTPUT_NAME njoy21
                           )

    target_link_libraries( njoy21
        PUBLIC ENDFtk
        PUBLIC RECONR
        PUBLIC tclap-adapter
        PUBLIC njoy_c_bindings
        PUBLIC lipservice
        PUBLIC dimwits
        PUBLIC utility
        )

    # unit testing
    if( unit_tests )
        include( cmake/unit_testing.cmake )
    endif()

    # integral testing
    message( STATUS "Adding integral testing" )
    enable_testing()
    add_subdirectory( tests )

endif()
