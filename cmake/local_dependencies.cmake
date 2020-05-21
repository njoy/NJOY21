cmake_minimum_required( VERSION 3.16 )

include( FetchContent )


#######################################################################
# Forward declarations
#######################################################################

FetchContent_Declare( ENDFtk
    URL     ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/ENDFtk/
    )


#######################################################################
# Declare project dependencies
#######################################################################



#######################################################################
# Load dependencies
#######################################################################

include( cmake/live_dependencies.cmake )
