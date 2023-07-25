cmake_minimum_required( VERSION 3.14 )
include( FetchContent )

#######################################################################
# Declare project dependencies
#######################################################################

FetchContent_Declare( leapr
    GIT_REPOSITORY  https://github.com/njoy/leapr
    GIT_TAG         ff2a1fa90f28e29b5eda100428c35150d1ff89f7
    )

FetchContent_Declare( catch-adapter
    GIT_REPOSITORY  https://github.com/njoy/catch-adapter
    GIT_TAG         fb84b82ebf7a4789aa43cea560680cf745c6ee4f
    )

FetchContent_Declare( dimwits
    GIT_REPOSITORY  https://github.com/njoy/DimensionalAnalysis
    GIT_TAG         acd794d373c8740a788f5c9d58a6eb8ba4d9861a
    )

FetchContent_Declare( disco
    GIT_REPOSITORY  https://github.com/njoy/disco
    GIT_TAG         a1a7ddb2c0f69465524d8640ee29988b714a881e
    )

FetchContent_Declare( ENDFtk
    GIT_REPOSITORY  https://github.com/njoy/ENDFtk
    GIT_TAG         d72711722a269919321e3f3df8a8b0cfe23ba6c7
    )

FetchContent_Declare( hana-adapter
    GIT_REPOSITORY  https://github.com/njoy/hana-adapter
    GIT_TAG         f58e8973c9a614dc4f3720b5581a762c61bdbb40
    )

FetchContent_Declare( header-utilities
    GIT_REPOSITORY  https://github.com/njoy/header-utilities
    GIT_TAG         cc2610fee15e255c151e8e22aca1e8b3d1a96b39
    )

FetchContent_Declare( lipservice
    GIT_REPOSITORY  https://github.com/njoy/lipservice
    GIT_TAG         1efa5e9452384a7bfc278fde57979c4d91e312c0
    )

FetchContent_Declare( Log
    GIT_REPOSITORY  https://github.com/njoy/Log
    GIT_TAG         52962b7796afe37ef1d8f7edb4bf9ecb1b868d15
    )

FetchContent_Declare( njoy
    GIT_REPOSITORY  http://github.com/njoy/NJOY2016
    GIT_TAG         e722511e88e4568502b51a15cebd38d03fd060a8 # tag: 2016.61
    )

FetchContent_Declare( njoy_c_bindings
    GIT_REPOSITORY  https://github.com/njoy/njoy_c_bindings
    GIT_TAG         48f2de6d8573a1a4234de85bc01c902c07eeceb5
    )

FetchContent_Declare( nlohmann_json
    GIT_REPOSITORY  https://github.com/nlohmann/json
    GIT_TAG         e7b3b40b5a95bc74b9a7f662830a27c49ffc01b4 # tag: v3.7.3
    )

FetchContent_Declare( range-v3-adapter
    GIT_REPOSITORY  https://github.com/njoy/range-v3-adapter
    GIT_TAG         252679d4737c8f755d87c0e1eed6c37394a2ec59
    )

FetchContent_Declare( spdlog
    GIT_REPOSITORY  https://github.com/gabime/spdlog
    GIT_TAG         a51b4856377a71f81b6d74b9af459305c4c644f8
    )

FetchContent_Declare( tclap-adapter
    GIT_REPOSITORY  https://github.com/njoy/tclap-adapter
    GIT_TAG         2642a0f6913c431608c7cd2c61607cb2d775d5b9
    )

FetchContent_Declare( utility
    GIT_REPOSITORY  https://github.com/njoy/utility
    GIT_TAG         4e72b708d153450bdbc7fc2b45651d71f9a183dc
    )

#######################################################################
# Load dependencies
#######################################################################

FetchContent_MakeAvailable(
    leapr
    catch-adapter
    dimwits
    disco
    ENDFtk
    hana-adapter
    header-utilities
    lipservice
    Log
    njoy
    njoy_c_bindings
    nlohmann_json
    range-v3-adapter
    spdlog
    tclap-adapter
    utility
    )
