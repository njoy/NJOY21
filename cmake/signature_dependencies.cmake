cmake_minimum_required( VERSION 3.16 )

include( FetchContent )


#######################################################################
# Forward declarations
#######################################################################

FetchContent_Declare( ENDFtk
    GIT_REPOSITORY  https://github.com/njoy/ENDFtk
    GIT_TAG         c10180074518a203de13cf41ff67b51fa6e002ac
    )

FetchContent_Declare( njoy
    GIT_REPOSITORY  https://github.com/njoy/NJOY2016
    GIT_TAG         2016.56
    )


#######################################################################
# Declare project dependencies
#######################################################################



#######################################################################
# Load dependencies
#######################################################################

include( cmake/live_dependencies.cmake )
