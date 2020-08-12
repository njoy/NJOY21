cmake_minimum_required( VERSION 3.16 )

include( FetchContent )


#######################################################################
# Forward declarations
#######################################################################


#######################################################################
# Declare project dependencies
#######################################################################

FetchContent_Declare( ENDFtk
    GIT_REPOSITORY  https://github.com/njoy/ENDFtk
    GIT_TAG         origin/build/fetchcontent
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( RECONR
    GIT_REPOSITORY  https://github.com/njoy/RECONR
    GIT_TAG         origin/NJOY21/integration
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( dimwits
    GIT_REPOSITORY  https://github.com/njoy/DimensionalAnalysis
    GIT_TAG         origin/build/fetchcontent
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( lipservice
    GIT_REPOSITORY  https://github.com/njoy/lipservice
    GIT_TAG         origin/build/fetchcontent
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( njoy_c_bindings
    GIT_REPOSITORY  https://github.com/njoy/njoy_c_bindings
    GIT_TAG         origin/build/fetchcontent
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( tclap-adapter
    GIT_REPOSITORY  https://github.com/njoy/tclap-adapter
    GIT_TAG         origin/master
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( utility
    GIT_REPOSITORY  https://github.com/njoy/utility
    GIT_TAG         origin/build/fetchcontent
    GIT_SHALLOW     TRUE
    )


#######################################################################
# Load dependencies
#######################################################################

FetchContent_MakeAvailable(
    ENDFtk
    RECONR
    dimwits
    lipservice
    njoy_c_bindings
    tclap-adapter
    utility
    )

