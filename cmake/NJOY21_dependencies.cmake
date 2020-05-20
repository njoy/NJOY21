cmake_minimum_required( VERSION 3.16 )

include( FetchContent )
cmake_policy( SET CMP0097 NEW )


#######################################################################
# Forward declarations
#######################################################################



#######################################################################
# Declare project dependencies
#######################################################################

FetchContent_Declare( ENDFtk
    GIT_REPOSITORY  https://github.com/njoy/ENDFtk
    GIT_TAG         origin/build/fetchcontent
    GIT_SUBMODULES  "src"
    )

FetchContent_Declare( dimwits
    GIT_REPOSITORY  https://github.com/njoy/DimensionalAnalysis
    GIT_TAG         origin/build/fetchcontent
    GIT_SUBMODULES  "src"
    )

FetchContent_Declare( lipservice
    GIT_REPOSITORY  https://github.com/njoy/lipservice
    GIT_TAG         origin/build/fetchcontent
    GIT_SUBMODULES  "src"
    )

FetchContent_Declare( njoy_c_bindings
    GIT_REPOSITORY  https://github.com/njoy/njoy_c_bindings
    GIT_TAG         0f158a3f4d2ea139a2fa02948a6419a5df61e049
    GIT_SUBMODULES  "src"
    )

FetchContent_Declare( tclap-adapter
    GIT_REPOSITORY  https://github.com/njoy/tclap-adapter
    GIT_TAG         origin/master
    GIT_SUBMODULES  "src"
    )

FetchContent_Declare( utility
    GIT_REPOSITORY  https://github.com/njoy/utility
    GIT_TAG         origin/build/fetchcontent
    GIT_SUBMODULES  "src"
    )


#######################################################################
# Load dependencies
#######################################################################

FetchContent_MakeAvailable(
    ENDFtk
    dimwits
    lipservice
    njoy_c_bindings
    tclap-adapter
    utility
    )

