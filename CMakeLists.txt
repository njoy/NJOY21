#######################################################################
# Preamble
#######################################################################

cmake_minimum_required( VERSION 3.16 )
project( NJOY21 LANGUAGES CXX )


#######################################################################
# Project-wide setup
#######################################################################

# list( APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake )
set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED YES )


#######################################################################
# Dependencies
#######################################################################

include( cmake/NJOY21_dependencies.cmake )


#######################################################################
# Main project targets
#######################################################################

add_library( njoy21 src/main.cpp )
target_include_directories( njoy21 PUBLIC src/ )
target_link_libraries( njoy21 PUBLIC ENDFtk
                              PUBLIC tclap-adapter
                              PUBLIC njoy_c_bindings
                              PUBLIC lipservice
                              PUBLIC dimwits
                              PUBLIC utility
                              )


#######################################################################
# Top-level Only
#######################################################################

if( CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR )

    # add NJOY21 executable
    add_executable( NJOY21_executable src/main.cpp )
    set_target_properties( NJOY21_executable
                           PROPERTIES OUTPUT_NAME njoy21
                           )
    target_link_libraries( NJOY21_executable PUBLIC njoy21 )

endif()
