
cmake_minimum_required( VERSION 3.2 ) 
set( CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Supported configuration types" FORCE )
        
if( NOT ROOT_DIRECTORY )
    set( ROOT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )
    if ( NOT fetched_subprojects )
        if ( NOT PYTHON_EXECUTABLE )
            find_package( PythonInterp )
            if ( NOT PYTHONINTERP_FOUND )
                message( FATAL_ERROR "Python interpeter installation was not found." )
            endif()
        endif()
        execute_process( COMMAND ${PYTHON_EXECUTABLE} "./metaconfigure/fetch_subprojects.py"
                         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} 
                         RESULT_VARIABLE fetch_failure )
        if ( NOT fetch_failure )
            set( fetched_subprojects TRUE CACHE BOOL "fetch script ran" )
        else()
            message( FATAL_ERROR "Failed to fetch dependencies" )
        endif()
    endif()
endif()

project( njoy21 LANGUAGES CXX )
get_directory_property( is_subproject PARENT_DIRECTORY )
include( CMakeDependentOption REQUIRED )
enable_language( Fortran )

set( njoy21_AppleClang_minimum_version 8.0 )
set( njoy21_GNU_minimum_version 6.2 )
set( njoy21_Clang_minimum_version 3.8 )

if( njoy21_${CMAKE_CXX_COMPILER_ID}_minimum_version )
    if( CMAKE_CXX_COMPILER_VERSION AND
        CMAKE_CXX_COMPILER_VERSION VERSION_LESS
        ${njoy21_${CMAKE_CXX_COMPILER_ID}_minimum_version} )
        message( FATAL_ERROR "${CMAKE_CXX_COMPILER_ID} version must be greater than ${njoy21_${CMAKE_CXX_COMPILER_ID}_minimum_version}" )
    endif()
endif()

# general properties
option( njoy21_strict "Compile time warnings are converted to errors" ON )

# binary instrumentation
option( coverage "Enable binary instrumentation to collect test coverage information in the DEBUG configuration" )
option( profile_generate "Enable binary instrumentation to generation execution profiles in the RELEASE configuration which may be used to guide later optimization" )

# additional optimizations
option( link_time_optimization "Enable link time optimization in the RELEASE configuration" )
option( profile_use "In the RELEASE configuration, leverage previously generated exeution profile to inform optimization decisions" )
option( nonportable_optimization "Enable optimizations which compromise portability of resulting binary in the RELEASE configuration" )

# libraries and linking
option( static "Statically link component and environment libraries" OFF )
if ( static AND ( "${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin" ) )
    message( FATAL_ERROR "Static binaries not supported on OSX" )
endif()

CMAKE_DEPENDENT_OPTION( static_libraries "Statically link component libraries" OFF "NOT static" ON )
CMAKE_DEPENDENT_OPTION( static_njoy21 "Statically link the njoy21 component library" OFF "NOT static;NOT static_libraries" ON ) 

option( unit_tests "Compile the njoy21 unit tests and integrate with ctest" ON ) 

if ( profile_generate AND profile_use )
    message( FATAL_ERROR "Cannot both generate and use execution profile in the same configuration" )
endif()

if ( profile_generate )
    file( MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/profiling" )
endif()

set( njoy21_AppleClang_Darwin_common_flags "-stdlib=libc++" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( njoy21_AppleClang_Darwin_DEBUG_flags "-O0" "-g" "-gdwarf-3" )
set( njoy21_AppleClang_Darwin_RELEASE_flags "-O3" "-DNDEBUG" )
set( njoy21_AppleClang_Darwin_strict_flags "-Werror" )
set( njoy21_AppleClang_Darwin_coverage_flags "--coverage" )
set( njoy21_AppleClang_Darwin_subproject_flags  )
set( njoy21_AppleClang_Darwin_base_project_flags  )
set( njoy21_AppleClang_Darwin_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_AppleClang_Darwin_link_time_optimization_flags "-flto" )
set( njoy21_AppleClang_Darwin_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_AppleClang_Darwin_nonportable_optimization_flags "-march=native" )
set( njoy21_AppleClang_Darwin_static_flags "-static" )
set( njoy21_GNU_Linux_common_flags "-Wno-subobject-linkage" "-Wall" "-Wextra" "-Wpedantic" "-Wno-maybe-uninitialized" "-std=c++14" )
set( njoy21_GNU_Linux_DEBUG_flags "-O0" "-g" "-gdwarf-3" "-fsignaling-nans" )
set( njoy21_GNU_Linux_RELEASE_flags "-O3" "-DNDEBUG" )
set( njoy21_GNU_Linux_strict_flags "-Werror" )
set( njoy21_GNU_Linux_coverage_flags "--coverage" )
set( njoy21_GNU_Linux_subproject_flags  )
set( njoy21_GNU_Linux_base_project_flags  )
set( njoy21_GNU_Linux_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_GNU_Linux_link_time_optimization_flags "-flto" )
set( njoy21_GNU_Linux_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_GNU_Linux_nonportable_optimization_flags "-march=native" )
set( njoy21_GNU_Linux_static_flags "-static" )
set( njoy21_GNU_Darwin_common_flags "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( njoy21_GNU_Darwin_DEBUG_flags "-O0" "-g" "-gdwarf-3" "-fsignaling-nans" )
set( njoy21_GNU_Darwin_RELEASE_flags "-O3" "-DNDEBUG" )
set( njoy21_GNU_Darwin_strict_flags "-Werror" )
set( njoy21_GNU_Darwin_coverage_flags "--coverage" )
set( njoy21_GNU_Darwin_subproject_flags  )
set( njoy21_GNU_Darwin_base_project_flags  )
set( njoy21_GNU_Darwin_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_GNU_Darwin_link_time_optimization_flags "-flto" )
set( njoy21_GNU_Darwin_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_GNU_Darwin_nonportable_optimization_flags "-march=native" )
set( njoy21_GNU_Darwin_static_flags "-static" )
set( njoy21_GNU_Windows_common_flags "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( njoy21_GNU_Windows_DEBUG_flags "-O0" "-g" "-gdwarf-3" "-fsignaling-nans" )
set( njoy21_GNU_Windows_RELEASE_flags "-O3" "-DNDEBUG" )
set( njoy21_GNU_Windows_strict_flags "-Werror" )
set( njoy21_GNU_Windows_coverage_flags "--coverage" )
set( njoy21_GNU_Windows_subproject_flags  )
set( njoy21_GNU_Windows_base_project_flags  )
set( njoy21_GNU_Windows_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_GNU_Windows_link_time_optimization_flags "-flto" )
set( njoy21_GNU_Windows_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_GNU_Windows_nonportable_optimization_flags "-march=native" )
set( njoy21_GNU_Windows_static_flags "-static" )
set( njoy21_Clang_Linux_common_flags "-stdlib=libstdc++" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( njoy21_Clang_Linux_DEBUG_flags "-O0" "-g" "-gdwarf-3" )
set( njoy21_Clang_Linux_RELEASE_flags "-O3" "-DNDEBUG" )
set( njoy21_Clang_Linux_strict_flags "-Werror" )
set( njoy21_Clang_Linux_coverage_flags "--coverage" )
set( njoy21_Clang_Linux_subproject_flags  )
set( njoy21_Clang_Linux_base_project_flags  )
set( njoy21_Clang_Linux_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_Clang_Linux_link_time_optimization_flags "-flto" )
set( njoy21_Clang_Linux_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_Clang_Linux_nonportable_optimization_flags "-march=native" )
set( njoy21_Clang_Linux_static_flags "-static" )
set( njoy21_Clang_Darwin_common_flags "-stdlib=libc++" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( njoy21_Clang_Darwin_DEBUG_flags "-O0" "-g" "-gdwarf-3" )
set( njoy21_Clang_Darwin_RELEASE_flags "-O3" "-DNDEBUG" )
set( njoy21_Clang_Darwin_strict_flags "-Werror" )
set( njoy21_Clang_Darwin_coverage_flags "--coverage" )
set( njoy21_Clang_Darwin_subproject_flags  )
set( njoy21_Clang_Darwin_base_project_flags  )
set( njoy21_Clang_Darwin_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_Clang_Darwin_link_time_optimization_flags "-flto" )
set( njoy21_Clang_Darwin_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_Clang_Darwin_nonportable_optimization_flags "-march=native" )
set( njoy21_Clang_Darwin_static_flags "-static" )
set( njoy21_Clang_Windows_common_flags "-stdlib=libc++" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( njoy21_Clang_Windows_DEBUG_flags "-O0" "-g" "-gdwarf-3" )
set( njoy21_Clang_Windows_RELEASE_flags "-O3" "-DNDEBUG" )
set( njoy21_Clang_Windows_strict_flags "-Werror" )
set( njoy21_Clang_Windows_coverage_flags "--coverage" )
set( njoy21_Clang_Windows_subproject_flags  )
set( njoy21_Clang_Windows_base_project_flags  )
set( njoy21_Clang_Windows_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_Clang_Windows_link_time_optimization_flags "-flto" )
set( njoy21_Clang_Windows_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( njoy21_Clang_Windows_nonportable_optimization_flags "-march=native" )
set( njoy21_Clang_Windows_static_flags "-static" )

if ( static_njoy21 )
    set( njoy21_library_linkage STATIC )
else ()
    set( njoy21_library_linkage SHARED )
endif () 

set( CMAKE_SKIP_BUILD_RPATH FALSE )
set( CMAKE_BUILD_WITH_INSTALL_RPATH FALSE )
if ( CMAKE_SYSTEM_NAME STREQUAL "Darwin" )
    set( rpath_prefix "@loader_path" )
else()
    set( rpath_prefix "\\$ORIGIN" )
endif()
list( INSERT 0 CMAKE_INSTALL_RPATH "${rpath_prefix}/../lib" )
set( CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE )
get_directory_property( is_subproject PARENT_DIRECTORY )

if( NOT TARGET catch-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/catch-adapter )
endif()

if( NOT TARGET hana-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/hana-adapter )
endif()

if( NOT TARGET dimwits )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/dimwits )
endif()

if( NOT TARGET disco )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/disco )
endif()

if( NOT TARGET fmt-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/fmt-adapter )
endif()

if( NOT TARGET spdlog-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/spdlog-adapter )
endif()

if( NOT TARGET Log )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/Log )
endif()

if( NOT TARGET header-utilities )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/header-utilities )
endif()

if( NOT TARGET hopscotch-map-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/hopscotch-map-adapter )
endif()

if( NOT TARGET range-v3-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/range-v3-adapter )
endif()

if( NOT TARGET variant-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/variant-adapter )
endif()

if( NOT TARGET ENDFtk )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/ENDFtk )
endif()

if( NOT TARGET njoy )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/njoy )
endif()

if( NOT TARGET njoy_c_bindings )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/njoy_c_bindings )
endif()

if( NOT TARGET tclap-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/tclap-adapter )
endif()

if( NOT TARGET utility )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/utility )
endif()


if ( NOT GIT_EXECUTABLE )
    find_package( Git )
    if ( NOT GIT_FOUND )
        message( FATAL_ERROR "git installation was not found." )
    endif()
endif()

execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse --abbrev-ref HEAD
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_BRANCH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
) 

message( STATUS "" )
message( STATUS "-----------------------------------------------------------" )
message( STATUS "" )
message( STATUS "njoy21" )
message( STATUS "Git current branch: ${GIT_BRANCH}" )
message( STATUS "Git commit hash: ${GIT_HASH}" )
message( STATUS "" )
message( STATUS "-----------------------------------------------------------" )

add_library( njoy21 ${njoy21_library_linkage} 
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/banner.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/CommandLine.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/Driver.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/interface.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/io.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/legacy.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/Sequence.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/Driver/Factory.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/Card.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GASPR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/Label.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PURR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/UNRESR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/VIEWR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card10.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card11.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card6.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card7.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card8.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card8a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card9.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card1/Nace.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card1/Ndir.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card1/Nendf.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card1/Ngend.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card1/Npend.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card2/Iopt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card2/Iprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card2/Itype.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card2/Nxtra.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card2/Suff.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card3/Hk.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card4/Izaw.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card6/Iopp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card6/Ismooth.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card6/Newfor.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card7/Thin1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card7/Thin2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card7/Thin3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card8/Tname.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card8a/Iza01.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card8a/Iza02.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card8a/Iza03.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card9/Emax.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card9/Ielas.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card9/Iwt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card9/Mte.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card9/Mti.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card9/Nbint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card9/Nmix.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/common.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/parser.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/policy.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/Type.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/common/Matd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/common/Nin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/common/Nout.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/common/Tempd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/parser/Base.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/parser/Composition.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/parser/Defaulted.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/parser/Discriminating.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/parser/FortranString.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/parser/Optional.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/parser/Required.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/parser/FortranString/src/isQuote.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/parser/FortranString/src/quoted.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/parser/FortranString/src/read.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/parser/FortranString/src/unquoted.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/parser/src/read.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/parser/src/rightShift.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/parser/src/validate.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/src/construct.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/src/domainError.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/src/echoLine.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/src/extract.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card1/Nendf.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card1/Nin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card1/Nout.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card2/Istart.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card2/Istrap.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card2/Mat1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card2/Ntemp2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card2/Temp1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card3/Errint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card3/Errmax.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card3/Errthn.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card3/Thnmax.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card4/Temp2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/Card5/Mat1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/BROADR/src/readCard5List.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CBRKXS.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card1/Nbrks.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card1/Ndlay.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card1/Nisot.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card2/Huse.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card2/Ivers.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card2/Lprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card3/Hsetid.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card4/Ifopt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card4/Maxord.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card4/Nggrup.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card4/Ngroup.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card4/Niso.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card5/Habsid.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card5/Hident.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card5/Hisnm.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card5/Hmat.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card5/Imat.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/Card5/Xspo.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CBRKXS/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CBRKXS/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CBRKXS/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CBRKXS/Card1/Nti.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CBRKXS/Card1/Nzi.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CBRKXS/Card2/Atem.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CBRKXS/Card3/Asig.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CBRKXS/src/readCard2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CBRKXS/src/readCard3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card1/Ichix.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card1/Maxdn.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card1/Maxup.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card1/Nsblok.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card2/Spec.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card3/Spec.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card4/Adens.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card4/Amass.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card4/Ecapt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card4/Efiss.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card4/Kbr.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card4/Sigpot.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/Card4/Temp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/src/readCard2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/src/readCard3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/CISOTX/src/readCard4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/src/readCard5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/src/readCBRKXS.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/CCCCR/src/readCISOTX.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card2a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card2b.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card2z.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card3a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card3b.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card3c.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card1/Nout.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card1/Nplot.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card2/Icolor.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card2a/Epmin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card2b/Matype.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card2b/Ncase.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card2z/Nlev.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card2z/Tlev.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card3a/Irelco.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card3a/Ncase.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card3a/Ndiv.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card3a/Noleg.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card3a/Nstart.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card3b/Hlibid.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card3c/Hdescr.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card4/Mat.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card4/Mat1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card4/Mt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/Card4/Mt1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/src/readCard23a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/src/readCard23b.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/COVR/src/readCard4List.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card3a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card6.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card7.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card8.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card1/Nout.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card1/Npend.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card1/Nplot.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card2/Iedit.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card2/Ifilm.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card2/Iprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card3/Ipingp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card3/Iptotl.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card3/Itabl.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card3/Ned.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card3/Ng.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card3/Nlmax.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card3/Ntherm.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card3a/Mtc.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card3a/Mti.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card3a/Nlc.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card4/HollerithNames.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card5/Jpos.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card5/Mt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card5/Mult.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card6/Ng.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card6/Nlmax.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card7/Ngp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card7/Nptabl.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card8/Dtemp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card8/Hisnam.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card8/Jsigz.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/DTFR/Card8/Mat.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/DummyMF33.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Card1/Nendf.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Card1/Ngout.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Card1/Nin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Card1/Nout.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Card1/Npend.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Card1/Nstan.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Card1/src/readRest.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/DummyMF33/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/DummyMF33/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/DummyMF33/Card2/Nout.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/DummyMF33/Card3/Mt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/DummyMF33/src/readCard3List.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card10.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card11.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card12a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card12b.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card13.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card13b.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card7.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card8.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card8a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card8b.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card9.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card10/Mat1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card10/Mt1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card10/src/readMt1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card11/Matb.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card11/Matc.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card11/Mtb.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card11/Mtc.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card11/src/readRest.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card12a/Ngn.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card12b/Egn.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card13/Wght.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card13b/Eb.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card13b/Ec.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card13b/Tb.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card13b/Tc.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card2/Ign.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card2/Iprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card2/Irelco.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card2/Iwt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card3/Mprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card3/Tempin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card7/Dap.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card7/Efmean.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card7/Ifissp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card7/Iread.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card7/Irespr.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card7/Legord.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card7/Mfcov.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card7/src/readDap.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card7/src/readIfisspEfmean.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card7/src/readIrespr.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card7/src/readLegord.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card8/Nek.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card8/Nmt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card8a/Mts.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card8b/Ek.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/Card9/Akxy.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/src/readCard10.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/src/readCard10List.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/src/readCard11.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/src/readCard12ab.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/src/readCard13.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/src/readCard13b.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/Normal/src/readIread1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/src/readDummyMF33.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ERRORR/src/readNormal.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card6.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card7.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card1/Ngam1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card1/Ngam2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card2/Iwt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card2/Lord.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card4/Egg.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card4/Ngg.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card6/Mfd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card6/Mtname.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card6/src/readRest.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/Card7/Matd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/src/Material.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/src/readArbitraryGammaStructure.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/src/readArbitraryWeights.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/src/readCard6List.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GAMINR/src/readMaterials.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GASPR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GASPR/Card1/Nendf.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GASPR/Card1/Nin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GASPR/Card1/Nout.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card10.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card6a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card6b.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card7a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card7b.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8b.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8c.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8d.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card9.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card1/Nendf.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card1/Ngout1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card1/Ngout2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card1/Npend.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card10/Matd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Igg.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Ign.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Iprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Ismooth.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Iwt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Lord.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Matb.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Nsigz.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Ntemp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card3/Title.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card4/Temp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card5/Sigz.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card6a/Ngn.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card6b/Egn.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card7a/Ngg.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card7b/Egg.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8a/Alpha2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8a/Alpha3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8a/Beta.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8a/Fehi.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8a/Gamma.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8a/Jsigz.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8a/Nflmax.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8a/Ninwt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8a/Sam.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8a/Sigpot.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8b/Wght.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8c/Eb.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8c/Ec.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8c/Tb.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8c/Tc.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card8d/Ninwt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card9/Mfd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card9/Mtd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card9/Mtname.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/src/readArbitraryGammaStructure.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/src/readArbitraryNeutronStructure.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/src/readCard9List.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/src/readFluxCalculatorParameters.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/src/readFluxParameters.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/src/readReactionMatrix.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card5a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card1/Nendf.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card1/Nin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card1/Nout.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card1/Nplot.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card2/Ed.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card2/Iprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card2/Local.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card2/Npk.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card2/Nqa.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card2/Ntemp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card3/Mtk.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card4/Mta.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card5/Qa.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card5a/Qbar.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/src/buildCard3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/src/buildControlTuple.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/src/ctor.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card10.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card11.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card12.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card13.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card14.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card15.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card16.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card17.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card18.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card19.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card20.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card6.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card7.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card8.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card9.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card10/Temp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card11/Delta.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card11/Ni.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card12/Rho.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card13/C.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card13/Tbeta.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card13/Twt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card14/Nd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card15/Oe.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card16/Ow.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card17/Dka.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card17/Nka.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card18/Skappa.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card19/Cfrac.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card2/Title.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card20/Comment.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card3/Iprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card3/Nphon.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card3/Ntempr.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card4/Ilog.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card4/Isabt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card4/Mat.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card4/Smin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card4/Za.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card5/Awr.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card5/Iel.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card5/Ncold.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card5/Npr.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card5/Nsk.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card5/Spr.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card6/Aws.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card6/B7.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card6/Mss.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card6/Nss.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card6/Sps.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card6/src/buildControlTuple.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card7/Lat.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card7/Nalpha.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card7/Nbeta.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card8/Alpha.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/Card9/Beta.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/src/buildCard20List.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/src/buildOscillatorTuple.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/src/buildPairCorrelTuple.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/src/buildTempSpecificTuple.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/src/tempLoop.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/LEAPR/src/tempLoopIter.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card10.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card6.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card7.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card8.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card9.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card1/Ngen1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card1/Ngen2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card1/Ngen3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card1/Ngen4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card1/Ngen5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card1/Ngen6.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card1/Ngen7.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card1/Nmatx.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card10/Hmat.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card10/Matgg.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card10/Matno.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card2/Huse.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card2/Ivers.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card3/Nholl.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card3/Nmat.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card3/Npart.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card3/Ntype.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card4/Hsetid.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card5/Hpart.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card6/Ngrp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card7/Htype.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card8/Jinp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/Card9/Joutp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/src/readCard10List.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MATXSR/src/readCard4List.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card6.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card1/Nin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card1/Nout.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card1/src/readNin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card2/Mtn.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card2/src/readMtn.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card3/Matn.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card3/Wtn.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card3/src/readMatnWtnList.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card4/Temp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card5/Awr.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card5/Za.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MIXR/Card6/Des.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER/Card1/Nin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER/Card1/Nout.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER/Card2/Tapeid.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER/Card3/Matd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER/Card3/Nin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card0.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card10.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card10a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card11.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card12.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card13.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card3a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card5a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card6.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card6a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card7.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card7a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card8.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card9.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card0/Nplt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card0/Nplt0.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card1/Ipcol.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card1/Istyle.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card1/Lori.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card1/Size.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card10/Aleg.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card10a/Xpoint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card10a/Xtag.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card10a/Ytag.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card11/X3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card11/Xv.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card11/Y3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card11/Yv.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card11/Z3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card11/Zv.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card12/Nform.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card13/Xdata.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card13/Xerr1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card13/Xerr2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card13/Ydata.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card13/Yerr1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card13/Yerr2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card2/Factx.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card2/Facty.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card2/Iplot.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card2/Iwcol.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card2/Ll.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card2/Wh.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card2/Wr.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card2/Ww.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card3/Title.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card4/Igrid.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card4/Ileg.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card4/Itype.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card4/Jtype.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card4/Xtag.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card4/Ytag.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card5/Eh.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card5/El.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card5/Xstep.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card5a/Xlabl.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card6/Yh.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card6/Yl.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card6/Ystep.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card6a/Ylabl.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card7/Rbot.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card7/Rstep.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card7/Rtop.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card8/Iverf.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card8/Matd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card8/Mfd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card8/Mtd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card8/Nin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card8/Nkh.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card8/Nth.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card8/Ntp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card8/Temper.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card9/Iccol.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card9/Icon.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card9/Idash.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card9/Ishade.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card9/Isym.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/Card9/Ithick.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/src/Curves.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/src/Freeform.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/src/Plot.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/src/readCard10.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/src/readCard10a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/src/readCard11.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/src/readCard13List.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/src/readCard7.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/src/readCard9.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/src/readCurves.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/src/readFreeform.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/src/readNtpNkh.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PLOTR/src/readPlot.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Card2/Iclaps.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Card2/Iprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Card2/Lib.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib1/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib1/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib1/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib1/Card6.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib1/Card3/Iff.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib1/Card3/Izref.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib1/Card3/Matd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib1/Card3/Nsgz.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib1/Card3/Rtemp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib1/Card3/src/readRest.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib1/Card4/Word.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib1/Card5/Fsn.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib1/Card6/Abs.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib1/src/readCard45.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib1/src/readCard6.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card3/Idtemp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card3/Matd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card3/Name.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card3/src/readRest.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card4/Itrc.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card4/Mtc.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card4/Mti.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card5/Alpha.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card5/KappaCapture.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card5/KappaFission.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card5/Lambda.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card5/Mubar.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card5/Nu.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card5/SigmaS.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/Card5/Xi.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib2/src/readCard45.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card10.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card11.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card11a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card12.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card12a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card12b.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card12c.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card6.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card7.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card8.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card9.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card10/Lambda.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card11/Resnu.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card11a/Tot.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card12/Fpa.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card12/Temp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card12a/Fis.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card12a/Nus.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card12a/Xtr.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card12b/Ia.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card12b/L1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card12b/L2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card12c/Scat.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card3/Idat.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card3/If4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card3/If5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card3/Iopt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card3/Mode.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card3/Newmat.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card3/Nlib.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card4/Mat.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card5/Inorf.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card5/Ip1opt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card5/Ires.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card5/Mtc.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card5/Mti.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card5/Nina.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card5/Nsigz.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card5/Ntemp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card5/Pos.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card5/Posr.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card5/Sgref.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card5/Sigp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card5/src/readMode0.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card5/src/readNina03.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card5/src/readNtapea0.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card6/Nfis.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card6/Ntis.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card7/Identb.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card8/Decay.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card8/Identa.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card8/Yield.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card9/Aw.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card9/Indfis.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/Card9/Ntemp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/src/readCard10.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/src/readCard11.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/src/readCard12.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/src/readCard4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/src/readCard5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/src/readCard678.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/Lib3/src/readCard9.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/src/readLib.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/src/readLib1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/POWR/src/readLib2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PURR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PURR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PURR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PURR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PURR/Card1/Nendf.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PURR/Card2/Iprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PURR/Card2/Nbin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PURR/Card2/Nladr.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PURR/Card2/Nsigz.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PURR/Card2/Ntemp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PURR/Card2/Nunx.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PURR/Card3/Temp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PURR/Card4/Sigz.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card6.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card1/Nendf.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card1/Npend.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card2/Tlabel.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card3/Mat.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card3/Ncards.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card3/Ngrid.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card4/Err.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card4/Errint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card4/Errmax.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card4/Tempr.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card5/Cards.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR/Card6/Enode.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card2/Efirst.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card2/Elast.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card2/Eps.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card2/Maxt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card2/Nholl.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card2/Nmat.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card3/Huse.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card3/Ivers.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card4/Holl.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card5/Hmat.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card5/Mat.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/Card5/Unit.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/src/readCard4List.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RESXSR/src/readCard5List.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card1/Nendf.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card1/Nin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card1/Nout.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card2/Icoh.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card2/Iform.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card2/Iin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card2/Iprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card2/Matde.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card2/Matdp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card2/Mtref.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card2/Natom.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card2/Nbin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card2/Ntemp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card3/Tempr.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card4/Emax.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/THERMR/Card4/Tol.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/UNRESR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/UNRESR/Card2/Iprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/VIEWR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/VIEWR/Card1/Infile.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/VIEWR/Card1/Nps.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card2a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card6a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card6b.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card6c.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card7.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card8.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card1/Nout.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card2/Igroup.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card2/Iprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card2/Iverw.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card2a/Igref.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card2a/Nfg.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card2a/Ngnd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card2a/Nrg.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card3/Iburn.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card3/Nfid.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card3/Rdfid.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card4/Ifprod.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card4/Inorf.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card4/Ip1opt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card4/Ires.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card4/Isof.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card4/Jp1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card4/Mtc.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card4/Mti.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card4/Nsigz.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card4/Ntemp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card4/Sgref.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card4/Sigp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card5/Efiss.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card5/Ntis.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card6a/Identa.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card6a/Yield.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card6b/Identa.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card6b/Lambda.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card6c/Identa.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card6c/Yield.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card7/Lambda.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/Card8/P1flx.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/src/readCard2a.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/src/readCard56.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/src/readCard7.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/WIMSR/src/readCard8.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/io/Manager.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/io/Manager/Builder.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/io/Manager/FileGaurd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/io/Manager/FortranOutput.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/legacy/Sequence.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/legacy/Sequence/Factory.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/legacy/Sequence/routines.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp" )

target_include_directories( njoy21 PUBLIC src )

set( PREFIX njoy21_${CMAKE_CXX_COMPILER_ID}_${CMAKE_SYSTEM_NAME} )

target_compile_options( njoy21 PRIVATE 
${${PREFIX}_common_flags}
$<$<BOOL:${njoy21_strict}>:${${PREFIX}_njoy21_strict_flags}>
$<$<BOOL:${static}>:${${PREFIX}_static_flags}>
$<$<BOOL:${is_subproject}>:${${PREFIX}_subproject_flags}>
$<$<NOT:$<BOOL:${is_subproject}>>:${${PREFIX}_base_project_flags}>
$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags} 
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags} 
$<$<BOOL:${profile_generate}>:${${PREFIX}_profile_generate_flags}> 
$<$<BOOL:${profile_use}>:${${PREFIX}_profile_use_flags}> 
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}> 
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>
${CXX_appended_flags} ${njoy21_appended_flags} )

target_link_libraries( njoy21 PUBLIC "$<$<AND:$<CONFIG:RELEASE>,$<BOOL:${link_time_optimization}>>:${${PREFIX}_RELEASE_flags};${${PREFIX}_link_time_optimization_flags}$<$<BOOL:${profile_generate}>:${${PREFIX}_profile_generate_flags};>$<$<BOOL:${profile_use}>:${${PREFIX}_profile_use_flags};>$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags};>>$<$<CONFIG:DEBUG>:$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags};>>$<$<BOOL:CXX_appended_flags>:${CXX_appended_flags};>$<$<BOOL:njoy21_appended_flags>:${njoy21_appended_flags};>" )

target_link_libraries( njoy21 PUBLIC dimwits PUBLIC ENDFtk PUBLIC njoy_c_bindings PUBLIC tclap-adapter PUBLIC utility PUBLIC variant-adapter )

if ( NOT is_subproject )
    add_executable( njoy21_executable src/main.cpp )
    set_target_properties( njoy21_executable PROPERTIES OUTPUT_NAME njoy21 )
    target_compile_options( njoy21_executable PRIVATE 
    ${${PREFIX}_common_flags}
    $<$<BOOL:${njoy21_strict}>:${${PREFIX}_njoy21_strict_flags}>
    $<$<BOOL:${static}>:${${PREFIX}_static_flags}>
    $<$<BOOL:${is_subproject}>:${${PREFIX}_subproject_flags}>
    $<$<NOT:$<BOOL:${is_subproject}>>:${${PREFIX}_base_project_flags}>
    $<$<CONFIG:DEBUG>:
    ${${PREFIX}_DEBUG_flags} 
    $<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
    $<$<CONFIG:RELEASE>:
    ${${PREFIX}_RELEASE_flags} 
    $<$<BOOL:${profile_generate}>:${${PREFIX}_profile_generate_flags}> 
    $<$<BOOL:${profile_use}>:${${PREFIX}_profile_use_flags}> 
    $<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}> 
    $<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>
    ${CXX_appended_flags} ${njoy21_appended_flags} )
    target_link_libraries( njoy21_executable PUBLIC njoy21 )
endif()

if( NOT is_subproject )
    enable_testing() 
    if ( unit_tests )
        add_subdirectory( src/njoy21/CommandLine/test )
        add_subdirectory( src/njoy21/Driver/test )
        add_subdirectory( src/njoy21/input/ACER/test )
        add_subdirectory( src/njoy21/input/ACER/Card1/test )
        add_subdirectory( src/njoy21/input/ACER/Card1/Nace/test )
        add_subdirectory( src/njoy21/input/ACER/Card1/Ndir/test )
        add_subdirectory( src/njoy21/input/ACER/Card1/Nendf/test )
        add_subdirectory( src/njoy21/input/ACER/Card1/Ngend/test )
        add_subdirectory( src/njoy21/input/ACER/Card1/Npend/test )
        add_subdirectory( src/njoy21/input/ACER/Card10/test )
        add_subdirectory( src/njoy21/input/ACER/Card11/test )
        add_subdirectory( src/njoy21/input/ACER/Card2/test )
        add_subdirectory( src/njoy21/input/ACER/Card2/Iopt/test )
        add_subdirectory( src/njoy21/input/ACER/Card2/Iprint/test )
        add_subdirectory( src/njoy21/input/ACER/Card2/Itype/test )
        add_subdirectory( src/njoy21/input/ACER/Card2/Nxtra/test )
        add_subdirectory( src/njoy21/input/ACER/Card2/Suff/test )
        add_subdirectory( src/njoy21/input/ACER/Card3/test )
        add_subdirectory( src/njoy21/input/ACER/Card3/Hk/test )
        add_subdirectory( src/njoy21/input/ACER/Card4/test )
        add_subdirectory( src/njoy21/input/ACER/Card4/Izaw/test )
        add_subdirectory( src/njoy21/input/ACER/Card5/test )
        add_subdirectory( src/njoy21/input/ACER/Card6/test )
        add_subdirectory( src/njoy21/input/ACER/Card6/Iopp/test )
        add_subdirectory( src/njoy21/input/ACER/Card6/Ismooth/test )
        add_subdirectory( src/njoy21/input/ACER/Card6/Newfor/test )
        add_subdirectory( src/njoy21/input/ACER/Card7/test )
        add_subdirectory( src/njoy21/input/ACER/Card7/Thin1/test )
        add_subdirectory( src/njoy21/input/ACER/Card7/Thin2/test )
        add_subdirectory( src/njoy21/input/ACER/Card7/Thin3/test )
        add_subdirectory( src/njoy21/input/ACER/Card8/test )
        add_subdirectory( src/njoy21/input/ACER/Card8/Tname/test )
        add_subdirectory( src/njoy21/input/ACER/Card8a/test )
        add_subdirectory( src/njoy21/input/ACER/Card8a/Iza01/test )
        add_subdirectory( src/njoy21/input/ACER/Card8a/Iza02/test )
        add_subdirectory( src/njoy21/input/ACER/Card9/test )
        add_subdirectory( src/njoy21/input/ACER/Card9/Emax/test )
        add_subdirectory( src/njoy21/input/ACER/Card9/Ielas/test )
        add_subdirectory( src/njoy21/input/ACER/Card9/Iwt/test )
        add_subdirectory( src/njoy21/input/ACER/Card9/Mte/test )
        add_subdirectory( src/njoy21/input/ACER/Card9/Mti/test )
        add_subdirectory( src/njoy21/input/ACER/Card9/Nbint/test )
        add_subdirectory( src/njoy21/input/ACER/Card9/Nmix/test )
        add_subdirectory( src/njoy21/input/BROADR/test )
        add_subdirectory( src/njoy21/input/BROADR/Card1/test )
        add_subdirectory( src/njoy21/input/BROADR/Card1/Nendf/test )
        add_subdirectory( src/njoy21/input/BROADR/Card1/Nin/test )
        add_subdirectory( src/njoy21/input/BROADR/Card1/Nout/test )
        add_subdirectory( src/njoy21/input/BROADR/Card2/test )
        add_subdirectory( src/njoy21/input/BROADR/Card2/Istart/test )
        add_subdirectory( src/njoy21/input/BROADR/Card2/Istrap/test )
        add_subdirectory( src/njoy21/input/BROADR/Card2/Mat1/test )
        add_subdirectory( src/njoy21/input/BROADR/Card2/Ntemp2/test )
        add_subdirectory( src/njoy21/input/BROADR/Card2/Temp1/test )
        add_subdirectory( src/njoy21/input/BROADR/Card3/test )
        add_subdirectory( src/njoy21/input/BROADR/Card3/Errint/test )
        add_subdirectory( src/njoy21/input/BROADR/Card3/Errmax/test )
        add_subdirectory( src/njoy21/input/BROADR/Card3/Errthn/test )
        add_subdirectory( src/njoy21/input/BROADR/Card3/Thnmax/test )
        add_subdirectory( src/njoy21/input/BROADR/Card4/test )
        add_subdirectory( src/njoy21/input/BROADR/Card4/Temp2/test )
        add_subdirectory( src/njoy21/input/BROADR/Card5/test )
        add_subdirectory( src/njoy21/input/BROADR/Card5/Mat1/test )
        add_subdirectory( src/njoy21/input/CCCCR/test )
        add_subdirectory( src/njoy21/input/CCCCR/CBRKXS/test )
        add_subdirectory( src/njoy21/input/CCCCR/CBRKXS/Card1/test )
        add_subdirectory( src/njoy21/input/CCCCR/CBRKXS/Card1/Nti/test )
        add_subdirectory( src/njoy21/input/CCCCR/CBRKXS/Card1/Nzi/test )
        add_subdirectory( src/njoy21/input/CCCCR/CBRKXS/Card2/test )
        add_subdirectory( src/njoy21/input/CCCCR/CBRKXS/Card2/Atem/test )
        add_subdirectory( src/njoy21/input/CCCCR/CBRKXS/Card3/test )
        add_subdirectory( src/njoy21/input/CCCCR/CBRKXS/Card3/Asig/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/Card1/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/Card1/Ichix/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/Card1/Maxdn/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/Card1/Maxup/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/Card1/Nsblok/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/Card2/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/Card2/Spec/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/Card3/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/Card3/Spec/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/Card4/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/Card4/Adens/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/Card4/Amass/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/Card4/Ecapt/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/Card4/Efiss/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/Card4/Sigpot/test )
        add_subdirectory( src/njoy21/input/CCCCR/CISOTX/Card4/Temp/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card1/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card1/Nbrks/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card1/Ndlay/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card1/Nisot/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card2/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card2/Huse/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card2/Ivers/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card2/Lprint/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card3/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card3/Hsetid/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card4/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card4/Ifopt/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card4/Maxord/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card4/Ngroup/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card4/Niso/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card5/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card5/Habsid/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card5/Hident/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card5/Hisnm/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card5/Hmat/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card5/Imat/test )
        add_subdirectory( src/njoy21/input/CCCCR/Card5/Xspo/test )
        add_subdirectory( src/njoy21/input/COVR/test )
        add_subdirectory( src/njoy21/input/COVR/Card1/test )
        add_subdirectory( src/njoy21/input/COVR/Card1/Nout/test )
        add_subdirectory( src/njoy21/input/COVR/Card1/Nplot/test )
        add_subdirectory( src/njoy21/input/COVR/Card2/test )
        add_subdirectory( src/njoy21/input/COVR/Card2/Icolor/test )
        add_subdirectory( src/njoy21/input/COVR/Card2a/test )
        add_subdirectory( src/njoy21/input/COVR/Card2a/Epmin/test )
        add_subdirectory( src/njoy21/input/COVR/Card2b/test )
        add_subdirectory( src/njoy21/input/COVR/Card2b/Matype/test )
        add_subdirectory( src/njoy21/input/COVR/Card2b/Ncase/test )
        add_subdirectory( src/njoy21/input/COVR/Card2z/test )
        add_subdirectory( src/njoy21/input/COVR/Card2z/Nlev/test )
        add_subdirectory( src/njoy21/input/COVR/Card2z/Tlev/test )
        add_subdirectory( src/njoy21/input/COVR/Card3a/test )
        add_subdirectory( src/njoy21/input/COVR/Card3a/Irelco/test )
        add_subdirectory( src/njoy21/input/COVR/Card3a/Ncase/test )
        add_subdirectory( src/njoy21/input/COVR/Card3a/Ndiv/test )
        add_subdirectory( src/njoy21/input/COVR/Card3a/Noleg/test )
        add_subdirectory( src/njoy21/input/COVR/Card3a/Nstart/test )
        add_subdirectory( src/njoy21/input/COVR/Card3b/test )
        add_subdirectory( src/njoy21/input/COVR/Card3b/Hlibid/test )
        add_subdirectory( src/njoy21/input/COVR/Card3c/test )
        add_subdirectory( src/njoy21/input/COVR/Card3c/Hdescr/test )
        add_subdirectory( src/njoy21/input/COVR/Card4/test )
        add_subdirectory( src/njoy21/input/COVR/Card4/Mat1/test )
        add_subdirectory( src/njoy21/input/Card/test )
        add_subdirectory( src/njoy21/input/DTFR/test )
        add_subdirectory( src/njoy21/input/DTFR/Card1/test )
        add_subdirectory( src/njoy21/input/DTFR/Card1/Nout/test )
        add_subdirectory( src/njoy21/input/DTFR/Card1/Npend/test )
        add_subdirectory( src/njoy21/input/DTFR/Card1/Nplot/test )
        add_subdirectory( src/njoy21/input/DTFR/Card2/test )
        add_subdirectory( src/njoy21/input/DTFR/Card2/Iedit/test )
        add_subdirectory( src/njoy21/input/DTFR/Card2/Ifilm/test )
        add_subdirectory( src/njoy21/input/DTFR/Card2/Iprint/test )
        add_subdirectory( src/njoy21/input/DTFR/Card3/test )
        add_subdirectory( src/njoy21/input/DTFR/Card3/Ipingp/test )
        add_subdirectory( src/njoy21/input/DTFR/Card3/Iptotl/test )
        add_subdirectory( src/njoy21/input/DTFR/Card3/Itabl/test )
        add_subdirectory( src/njoy21/input/DTFR/Card3/Ned/test )
        add_subdirectory( src/njoy21/input/DTFR/Card3/Ng/test )
        add_subdirectory( src/njoy21/input/DTFR/Card3/Nlmax/test )
        add_subdirectory( src/njoy21/input/DTFR/Card3/Ntherm/test )
        add_subdirectory( src/njoy21/input/DTFR/Card3a/test )
        add_subdirectory( src/njoy21/input/DTFR/Card3a/Mtc/test )
        add_subdirectory( src/njoy21/input/DTFR/Card3a/Mti/test )
        add_subdirectory( src/njoy21/input/DTFR/Card3a/Nlc/test )
        add_subdirectory( src/njoy21/input/DTFR/Card4/test )
        add_subdirectory( src/njoy21/input/DTFR/Card4/HollerithNames/test )
        add_subdirectory( src/njoy21/input/DTFR/Card5/test )
        add_subdirectory( src/njoy21/input/DTFR/Card5/Jpos/test )
        add_subdirectory( src/njoy21/input/DTFR/Card5/Mt/test )
        add_subdirectory( src/njoy21/input/DTFR/Card5/Mult/test )
        add_subdirectory( src/njoy21/input/DTFR/Card6/test )
        add_subdirectory( src/njoy21/input/DTFR/Card6/Ng/test )
        add_subdirectory( src/njoy21/input/DTFR/Card6/Nlmax/test )
        add_subdirectory( src/njoy21/input/DTFR/Card7/test )
        add_subdirectory( src/njoy21/input/DTFR/Card7/Ngp/test )
        add_subdirectory( src/njoy21/input/DTFR/Card7/Nptabl/test )
        add_subdirectory( src/njoy21/input/DTFR/Card8/test )
        add_subdirectory( src/njoy21/input/DTFR/Card8/Dtemp/test )
        add_subdirectory( src/njoy21/input/DTFR/Card8/Hisnam/test )
        add_subdirectory( src/njoy21/input/DTFR/Card8/Jsigz/test )
        add_subdirectory( src/njoy21/input/DTFR/Card8/Mat/test )
        add_subdirectory( src/njoy21/input/ERRORR/test )
        add_subdirectory( src/njoy21/input/ERRORR/Card1/test )
        add_subdirectory( src/njoy21/input/ERRORR/Card1/Nendf/test )
        add_subdirectory( src/njoy21/input/ERRORR/Card1/Ngout/test )
        add_subdirectory( src/njoy21/input/ERRORR/Card1/Nin/test )
        add_subdirectory( src/njoy21/input/ERRORR/Card1/Nout/test )
        add_subdirectory( src/njoy21/input/ERRORR/Card1/Npend/test )
        add_subdirectory( src/njoy21/input/ERRORR/Card1/Nstan/test )
        add_subdirectory( src/njoy21/input/ERRORR/DummyMF33/test )
        add_subdirectory( src/njoy21/input/ERRORR/DummyMF33/Card2/test )
        add_subdirectory( src/njoy21/input/ERRORR/DummyMF33/Card2/Nout/test )
        add_subdirectory( src/njoy21/input/ERRORR/DummyMF33/Card3/test )
        add_subdirectory( src/njoy21/input/ERRORR/DummyMF33/Card3/Mt/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card10/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card10/Mat1/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card10/Mt1/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card11/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card11/Matb/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card11/Matc/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card11/Mtb/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card11/Mtc/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card12a/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card12a/Ngn/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card12b/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card12b/Egn/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card13/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card13/Wght/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card13b/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card13b/Eb/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card13b/Ec/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card13b/Tb/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card13b/Tc/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card2/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card2/Ign/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card2/Iprint/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card2/Irelco/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card2/Iwt/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card3/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card3/Mprint/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card3/Tempin/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card7/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card7/Dap/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card7/Efmean/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card7/Ifissp/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card7/Iread/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card7/Irespr/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card7/Legord/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card7/Mfcov/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card8/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card8/Nek/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card8/Nmt/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card8a/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card8a/Mts/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card8b/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card8b/Ek/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card9/test )
        add_subdirectory( src/njoy21/input/ERRORR/Normal/Card9/Akxy/test )
        add_subdirectory( src/njoy21/input/GAMINR/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card1/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card1/Nendf/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card1/Ngam1/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card1/Ngam2/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card1/Npend/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card2/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card2/Iwt/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card2/Lord/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card3/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card4/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card4/Egg/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card4/Ngg/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card5/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card6/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card6/Mfd/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card6/Mtname/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card7/test )
        add_subdirectory( src/njoy21/input/GAMINR/Card7/Matd/test )
        add_subdirectory( src/njoy21/input/GASPR/test )
        add_subdirectory( src/njoy21/input/GASPR/Card1/test )
        add_subdirectory( src/njoy21/input/GASPR/Card1/Nendf/test )
        add_subdirectory( src/njoy21/input/GASPR/Card1/Nin/test )
        add_subdirectory( src/njoy21/input/GASPR/Card1/Nout/test )
        add_subdirectory( src/njoy21/input/GROUPR/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card1/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card1/Nendf/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card1/Ngout1/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card1/Ngout2/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card1/Npend/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card10/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card10/Matd/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Igg/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Ign/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Iprint/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Ismooth/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Iwt/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Lord/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Matb/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Nsigz/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Ntemp/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card3/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card3/Title/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card4/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card4/Temp/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card5/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card5/Sigz/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card6a/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card6a/Ngn/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card6b/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card6b/Egn/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card7a/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card7a/Ngg/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card7b/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card7b/Egg/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8a/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8a/Alpha2/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8a/Alpha3/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8a/Beta/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8a/Fehi/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8a/Gamma/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8a/Jsigz/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8a/Nflmax/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8a/Ninwt/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8a/Sam/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8a/Sigpot/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8b/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8b/Wght/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8c/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8c/Eb/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8c/Ec/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8c/Tb/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8c/Tc/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8d/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card8d/Ninwt/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card9/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card9/Mfd/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card9/Mtd/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card9/Mtname/test )
        add_subdirectory( src/njoy21/input/HEATR/test )
        add_subdirectory( src/njoy21/input/HEATR/Card1/test )
        add_subdirectory( src/njoy21/input/HEATR/Card1/Nendf/test )
        add_subdirectory( src/njoy21/input/HEATR/Card1/Nin/test )
        add_subdirectory( src/njoy21/input/HEATR/Card1/Nout/test )
        add_subdirectory( src/njoy21/input/HEATR/Card1/Nplot/test )
        add_subdirectory( src/njoy21/input/HEATR/Card2/test )
        add_subdirectory( src/njoy21/input/HEATR/Card2/Ed/test )
        add_subdirectory( src/njoy21/input/HEATR/Card2/Iprint/test )
        add_subdirectory( src/njoy21/input/HEATR/Card2/Local/test )
        add_subdirectory( src/njoy21/input/HEATR/Card2/Npk/test )
        add_subdirectory( src/njoy21/input/HEATR/Card2/Nqa/test )
        add_subdirectory( src/njoy21/input/HEATR/Card2/Ntemp/test )
        add_subdirectory( src/njoy21/input/HEATR/Card3/test )
        add_subdirectory( src/njoy21/input/HEATR/Card3/Mtk/test )
        add_subdirectory( src/njoy21/input/HEATR/Card4/test )
        add_subdirectory( src/njoy21/input/HEATR/Card4/Mta/test )
        add_subdirectory( src/njoy21/input/HEATR/Card5/test )
        add_subdirectory( src/njoy21/input/HEATR/Card5/Qa/test )
        add_subdirectory( src/njoy21/input/HEATR/Card5a/test )
        add_subdirectory( src/njoy21/input/HEATR/Card5a/Qbar/test )
        add_subdirectory( src/njoy21/input/LEAPR/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card1/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card10/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card10/Temp/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card11/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card11/Delta/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card11/Ni/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card12/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card12/Rho/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card13/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card13/C/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card13/Tbeta/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card13/Twt/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card14/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card14/Nd/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card15/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card15/Oe/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card16/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card16/Ow/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card17/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card17/Dka/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card17/Nka/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card18/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card18/Skappa/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card19/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card19/Cfrac/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card2/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card2/Title/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card20/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card20/Comment/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card3/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card3/Iprint/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card3/Nphon/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card3/Ntempr/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card4/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card4/Ilog/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card4/Isabt/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card4/Mat/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card4/Za/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card5/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card5/Awr/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card5/Iel/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card5/Ncold/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card5/Npr/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card5/Nsk/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card5/Spr/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card6/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card6/Aws/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card6/B7/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card6/Mss/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card6/Nss/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card6/Sps/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card7/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card7/Lat/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card7/Nalpha/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card7/Nbeta/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card8/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card8/Alpha/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card9/test )
        add_subdirectory( src/njoy21/input/LEAPR/Card9/Beta/test )
        add_subdirectory( src/njoy21/input/Label/test )
        add_subdirectory( src/njoy21/input/MATXSR/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card1/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card1/Ngen1/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card1/Ngen2/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card1/Ngen3/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card1/Ngen4/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card1/Ngen5/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card1/Ngen6/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card1/Ngen7/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card1/Nmatx/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card10/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card10/Hmat/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card10/Matgg/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card10/Matno/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card2/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card2/Huse/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card2/Ivers/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card3/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card3/Nholl/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card3/Nmat/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card3/Npart/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card3/Ntype/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card4/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card4/Hsetid/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card5/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card5/Hpart/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card6/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card6/Ngrp/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card7/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card7/Htype/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card8/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card8/Jinp/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card9/test )
        add_subdirectory( src/njoy21/input/MATXSR/Card9/Joutp/test )
        add_subdirectory( src/njoy21/input/MIXR/test )
        add_subdirectory( src/njoy21/input/MIXR/Card1/test )
        add_subdirectory( src/njoy21/input/MIXR/Card2/test )
        add_subdirectory( src/njoy21/input/MIXR/Card2/Mtn/test )
        add_subdirectory( src/njoy21/input/MIXR/Card3/test )
        add_subdirectory( src/njoy21/input/MIXR/Card3/Matn/test )
        add_subdirectory( src/njoy21/input/MIXR/Card3/Wtn/test )
        add_subdirectory( src/njoy21/input/MIXR/Card4/test )
        add_subdirectory( src/njoy21/input/MIXR/Card4/Temp/test )
        add_subdirectory( src/njoy21/input/MIXR/Card5/test )
        add_subdirectory( src/njoy21/input/MIXR/Card5/Awr/test )
        add_subdirectory( src/njoy21/input/MIXR/Card5/Za/test )
        add_subdirectory( src/njoy21/input/MIXR/Card6/test )
        add_subdirectory( src/njoy21/input/MIXR/Card6/Des/test )
        add_subdirectory( src/njoy21/input/MODER/test )
        add_subdirectory( src/njoy21/input/MODER/Card1/test )
        add_subdirectory( src/njoy21/input/MODER/Card1/Nin/test )
        add_subdirectory( src/njoy21/input/MODER/Card1/Nout/test )
        add_subdirectory( src/njoy21/input/MODER/Card2/test )
        add_subdirectory( src/njoy21/input/MODER/Card2/Tapeid/test )
        add_subdirectory( src/njoy21/input/MODER/Card3/test )
        add_subdirectory( src/njoy21/input/MODER/Card3/Matd/test )
        add_subdirectory( src/njoy21/input/MODER/Card3/Nin/test )
        add_subdirectory( src/njoy21/input/PLOTR/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card0/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card0/Nplt/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card0/Nplt0/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card1/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card1/Ipcol/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card1/Istyle/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card1/Lori/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card1/Size/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card10/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card10a/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card10a/Xpoint/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card10a/Xtag/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card10a/Ytag/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card11/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card12/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card12/Nform/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card13/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card13/Xdata/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card13/Xerr1/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card13/Xerr2/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card13/Ydata/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card13/Yerr1/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card13/Yerr2/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card2/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card2/Factx/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card2/Facty/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card2/Iplot/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card2/Ll/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card2/Wh/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card2/Wr/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card2/Ww/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card3/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card3/Title/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card3a/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card4/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card4/Igrid/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card4/Ileg/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card4/Itype/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card4/Jtype/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card4/Xtag/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card4/Ytag/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card5/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card5/Eh/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card5/El/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card5/Xstep/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card5a/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card6/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card6/Yh/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card6/Yl/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card6/Ystep/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card6a/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card7/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card7/Rbot/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card7/Rstep/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card7/Rtop/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card7a/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card8/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card8/Iverf/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card8/Matd/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card8/Mfd/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card8/Mtd/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card8/Nin/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card8/Nkh/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card8/Nth/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card8/Ntp/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card8/Temper/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card9/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card9/Iccol/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card9/Icon/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card9/Idash/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card9/Ishade/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card9/Isym/test )
        add_subdirectory( src/njoy21/input/PLOTR/Card9/Ithick/test )
        add_subdirectory( src/njoy21/input/POWR/test )
        add_subdirectory( src/njoy21/input/POWR/Card2/test )
        add_subdirectory( src/njoy21/input/POWR/Card2/Iclaps/test )
        add_subdirectory( src/njoy21/input/POWR/Card2/Iprint/test )
        add_subdirectory( src/njoy21/input/POWR/Card2/Lib/test )
        add_subdirectory( src/njoy21/input/POWR/Lib1/test )
        add_subdirectory( src/njoy21/input/POWR/Lib1/Card3/test )
        add_subdirectory( src/njoy21/input/POWR/Lib1/Card3/Iff/test )
        add_subdirectory( src/njoy21/input/POWR/Lib1/Card3/Izref/test )
        add_subdirectory( src/njoy21/input/POWR/Lib1/Card3/Matd/test )
        add_subdirectory( src/njoy21/input/POWR/Lib1/Card3/Nsgz/test )
        add_subdirectory( src/njoy21/input/POWR/Lib1/Card3/Rtemp/test )
        add_subdirectory( src/njoy21/input/POWR/Lib1/Card4/test )
        add_subdirectory( src/njoy21/input/POWR/Lib1/Card4/Word/test )
        add_subdirectory( src/njoy21/input/POWR/Lib1/Card5/test )
        add_subdirectory( src/njoy21/input/POWR/Lib1/Card5/Fsn/test )
        add_subdirectory( src/njoy21/input/POWR/Lib1/Card6/test )
        add_subdirectory( src/njoy21/input/POWR/Lib1/Card6/Abs/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card3/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card3/Idtemp/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card3/Matd/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card3/Name/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card4/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card4/Itrc/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card4/Mtc/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card4/Mti/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card5/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card5/Alpha/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card5/KappaCapture/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card5/KappaFission/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card5/Lambda/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card5/Mubar/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card5/Nu/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card5/SigmaS/test )
        add_subdirectory( src/njoy21/input/POWR/Lib2/Card5/Xi/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card10/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card11/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card11a/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card12/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card12/Temp/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card12a/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card12b/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card12b/Ia/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card12b/L1/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card12b/L2/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card12c/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card12c/Scat/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card3/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card3/Idat/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card3/If4/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card3/If5/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card3/Iopt/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card3/Mode/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card3/Newmat/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card3/Nlib/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card4/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card5/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card5/Inorf/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card5/Ip1opt/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card5/Ires/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card5/Mtc/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card5/Mti/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card5/Nina/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card5/Nsigz/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card5/Ntemp/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card5/Pos/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card5/Posr/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card5/Sgref/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card5/Sigp/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card6/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card6/Nfis/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card6/Ntis/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card7/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card7/Identb/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card8/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card8/Decay/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card8/Identa/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card8/Yield/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card9/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card9/Aw/test )
        add_subdirectory( src/njoy21/input/POWR/Lib3/Card9/Ntemp/test )
        add_subdirectory( src/njoy21/input/PURR/test )
        add_subdirectory( src/njoy21/input/PURR/Card1/test )
        add_subdirectory( src/njoy21/input/PURR/Card1/Nendf/test )
        add_subdirectory( src/njoy21/input/PURR/Card2/test )
        add_subdirectory( src/njoy21/input/PURR/Card2/Iprint/test )
        add_subdirectory( src/njoy21/input/PURR/Card2/Nbin/test )
        add_subdirectory( src/njoy21/input/PURR/Card2/Nladr/test )
        add_subdirectory( src/njoy21/input/PURR/Card2/Nsigz/test )
        add_subdirectory( src/njoy21/input/PURR/Card2/Ntemp/test )
        add_subdirectory( src/njoy21/input/PURR/Card2/Nunx/test )
        add_subdirectory( src/njoy21/input/PURR/Card3/test )
        add_subdirectory( src/njoy21/input/PURR/Card3/Temp/test )
        add_subdirectory( src/njoy21/input/PURR/Card4/test )
        add_subdirectory( src/njoy21/input/PURR/Card4/Sigz/test )
        add_subdirectory( src/njoy21/input/RECONR/test )
        add_subdirectory( src/njoy21/input/RECONR/Card1/test )
        add_subdirectory( src/njoy21/input/RECONR/Card1/Nendf/test )
        add_subdirectory( src/njoy21/input/RECONR/Card1/Npend/test )
        add_subdirectory( src/njoy21/input/RECONR/Card2/test )
        add_subdirectory( src/njoy21/input/RECONR/Card2/Tlabel/test )
        add_subdirectory( src/njoy21/input/RECONR/Card3/test )
        add_subdirectory( src/njoy21/input/RECONR/Card3/Mat/test )
        add_subdirectory( src/njoy21/input/RECONR/Card3/Ncards/test )
        add_subdirectory( src/njoy21/input/RECONR/Card3/Ngrid/test )
        add_subdirectory( src/njoy21/input/RECONR/Card4/test )
        add_subdirectory( src/njoy21/input/RECONR/Card4/Err/test )
        add_subdirectory( src/njoy21/input/RECONR/Card4/Errint/test )
        add_subdirectory( src/njoy21/input/RECONR/Card4/Errmax/test )
        add_subdirectory( src/njoy21/input/RECONR/Card4/Tempr/test )
        add_subdirectory( src/njoy21/input/RECONR/Card5/test )
        add_subdirectory( src/njoy21/input/RECONR/Card5/Cards/test )
        add_subdirectory( src/njoy21/input/RECONR/Card6/test )
        add_subdirectory( src/njoy21/input/RECONR/Card6/Enode/test )
        add_subdirectory( src/njoy21/input/RESXSR/test )
        add_subdirectory( src/njoy21/input/RESXSR/Card2/test )
        add_subdirectory( src/njoy21/input/RESXSR/Card2/Efirst/test )
        add_subdirectory( src/njoy21/input/RESXSR/Card2/Elast/test )
        add_subdirectory( src/njoy21/input/RESXSR/Card2/Eps/test )
        add_subdirectory( src/njoy21/input/RESXSR/Card2/Nholl/test )
        add_subdirectory( src/njoy21/input/RESXSR/Card2/Nmat/test )
        add_subdirectory( src/njoy21/input/RESXSR/Card3/test )
        add_subdirectory( src/njoy21/input/RESXSR/Card3/Huse/test )
        add_subdirectory( src/njoy21/input/RESXSR/Card4/test )
        add_subdirectory( src/njoy21/input/RESXSR/Card4/Holl/test )
        add_subdirectory( src/njoy21/input/RESXSR/Card5/test )
        add_subdirectory( src/njoy21/input/RESXSR/Card5/Hmat/test )
        add_subdirectory( src/njoy21/input/RESXSR/Card5/Mat/test )
        add_subdirectory( src/njoy21/input/RESXSR/Card5/Unit/test )
        add_subdirectory( src/njoy21/input/THERMR/test )
        add_subdirectory( src/njoy21/input/THERMR/Card1/test )
        add_subdirectory( src/njoy21/input/THERMR/Card1/Nendf/test )
        add_subdirectory( src/njoy21/input/THERMR/Card1/Nin/test )
        add_subdirectory( src/njoy21/input/THERMR/Card1/Nout/test )
        add_subdirectory( src/njoy21/input/THERMR/Card2/test )
        add_subdirectory( src/njoy21/input/THERMR/Card2/Icoh/test )
        add_subdirectory( src/njoy21/input/THERMR/Card2/Iform/test )
        add_subdirectory( src/njoy21/input/THERMR/Card2/Iin/test )
        add_subdirectory( src/njoy21/input/THERMR/Card2/Iprint/test )
        add_subdirectory( src/njoy21/input/THERMR/Card2/Matde/test )
        add_subdirectory( src/njoy21/input/THERMR/Card2/Matdp/test )
        add_subdirectory( src/njoy21/input/THERMR/Card2/Mtref/test )
        add_subdirectory( src/njoy21/input/THERMR/Card2/Natom/test )
        add_subdirectory( src/njoy21/input/THERMR/Card2/Nbin/test )
        add_subdirectory( src/njoy21/input/THERMR/Card2/Ntemp/test )
        add_subdirectory( src/njoy21/input/THERMR/Card3/test )
        add_subdirectory( src/njoy21/input/THERMR/Card3/Tempr/test )
        add_subdirectory( src/njoy21/input/THERMR/Card4/test )
        add_subdirectory( src/njoy21/input/THERMR/Card4/Emax/test )
        add_subdirectory( src/njoy21/input/THERMR/Card4/Tol/test )
        add_subdirectory( src/njoy21/input/UNRESR/test )
        add_subdirectory( src/njoy21/input/UNRESR/Card2/test )
        add_subdirectory( src/njoy21/input/UNRESR/Card2/Iprint/test )
        add_subdirectory( src/njoy21/input/VIEWR/test )
        add_subdirectory( src/njoy21/input/VIEWR/Card1/test )
        add_subdirectory( src/njoy21/input/VIEWR/Card1/Infile/test )
        add_subdirectory( src/njoy21/input/VIEWR/Card1/Nps/test )
        add_subdirectory( src/njoy21/input/WIMSR/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card1/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card1/Nout/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card2/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card2/Igroup/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card2/Iprint/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card2/Iverw/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card2a/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card2a/Igref/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card2a/Nfg/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card2a/Ngnd/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card2a/Nrg/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card3/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card3/Iburn/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card3/Nfid/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card3/Rdfid/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card4/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card4/Ifprod/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card4/Inorf/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card4/Ip1opt/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card4/Ires/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card4/Isof/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card4/Jp1/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card4/Mtc/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card4/Mti/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card4/Nsigz/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card4/Ntemp/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card4/Sgref/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card4/Sigp/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card5/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card5/Efiss/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card5/Ntis/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card6a/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card6a/Identa/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card6a/Yield/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card6b/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card6b/Identa/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card6b/Lambda/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card6c/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card6c/Identa/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card6c/Yield/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card7/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card7/Lambda/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card8/test )
        add_subdirectory( src/njoy21/input/WIMSR/Card8/P1flx/test )
        add_subdirectory( src/njoy21/input/argument/test )
        add_subdirectory( src/njoy21/input/argument/Type/test )
        add_subdirectory( src/njoy21/input/argument/common/Tempd/test )
        add_subdirectory( src/njoy21/input/argument/parser/test )
        add_subdirectory( src/njoy21/io/Manager/test )
        add_subdirectory( src/njoy21/legacy/Sequence/test )
    endif() 
    add_subdirectory( tests )
endif()

set( installation_targets njoy21 )
if ( NOT is_subproject )
    list( APPEND installation_targets njoy21_executable )
endif()

install( TARGETS ${installation_targets} 
         RUNTIME DESTINATION bin
         LIBRARY DESTINATION lib
         ARCHIVE DESTINATION lib
         PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ 
                     GROUP_EXECUTE GROUP_READ 
                     WORLD_EXECUTE WORLD_READ )

install( DIRECTORY src/ DESTINATION include
         FILE_PERMISSIONS OWNER_READ OWNER_WRITE 
                          GROUP_READ 
                          WORLD_READ
         DIRECTORY_PERMISSIONS OWNER_READ OWNER_WRITE 
                               GROUP_READ 
                               WORLD_READ
         FILES_MATCHING REGEX ".*\.h[+][+]$|.*\.hxx$|.*\.hpp$|.*\.hh$|.*\.h$"  )
