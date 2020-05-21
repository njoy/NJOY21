cmake_minimum_required( VERSION 3.16 )

include( FetchContent )


#######################################################################
# Forward declarations
#######################################################################

FetchContent_Declare( ENDFtk
    GIT_REPOSITORY  https://github.com/njoy/ENDFtk
    GIT_TAG         0a1dae7910aa4bb402ec03537f87113394a6db1a
    )


#######################################################################
# Declare project dependencies
#######################################################################



#######################################################################
# Load dependencies
#######################################################################

include( cmake/live_dependencies.cmake )
