
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

project( NJOY21 LANGUAGES CXX )
get_directory_property( is_subproject PARENT_DIRECTORY )
include( CMakeDependentOption REQUIRED )
enable_language( Fortran )

set( NJOY21_Clang_minimum_version 3.8 )
set( NJOY21_GNU_minimum_version 6.2 )
set( NJOY21_AppleClang_minimum_version 8.0 )

if( NJOY21_${CMAKE_CXX_COMPILER_ID}_minimum_version )
    if( CMAKE_CXX_COMPILER_VERSION AND
        CMAKE_CXX_COMPILER_VERSION VERSION_LESS
        ${NJOY21_${CMAKE_CXX_COMPILER_ID}_minimum_version} )
        message( FATAL_ERROR "${CMAKE_CXX_COMPILER_ID} version must be greater than ${NJOY21_${CMAKE_CXX_COMPILER_ID}_minimum_version}" )
    endif()
endif()

# general properties
option( NJOY21_strict "Compile time warnings are converted to errors" ON )

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
CMAKE_DEPENDENT_OPTION( static_NJOY21 "Statically link the NJOY21 component library" OFF "NOT static;NOT static_libraries" ON ) 

option( unit_tests "Compile the NJOY21 unit tests and integrate with ctest" ON ) 

if ( profile_generate AND profile_use )
    message( FATAL_ERROR "Cannot both generate and use execution profile in the same configuration" )
endif()

if ( profile_generate )
    file( MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/profiling" )
endif()

set( NJOY21_Clang_Darwin_common_flags "-stdlib=libc++" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( NJOY21_Clang_Darwin_DEBUG_flags "-O0" "-g" "-gdwarf-3" )
set( NJOY21_Clang_Darwin_RELEASE_flags "-O3" "-DNDEBUG" )
set( NJOY21_Clang_Darwin_strict_flags "-Werror" )
set( NJOY21_Clang_Darwin_coverage_flags "--coverage" )
set( NJOY21_Clang_Darwin_subproject_flags  )
set( NJOY21_Clang_Darwin_base_project_flags  )
set( NJOY21_Clang_Darwin_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( NJOY21_Clang_Darwin_link_time_optimization_flags "-flto" )
set( NJOY21_Clang_Darwin_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( NJOY21_Clang_Darwin_nonportable_optimization_flags "-march=native" )
set( NJOY21_Clang_Darwin_static_flags "-static" )
set( NJOY21_Clang_Linux_common_flags "-stdlib=libstdc++" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( NJOY21_Clang_Linux_DEBUG_flags "-O0" "-g" "-gdwarf-3" )
set( NJOY21_Clang_Linux_RELEASE_flags "-O3" "-DNDEBUG" )
set( NJOY21_Clang_Linux_strict_flags "-Werror" )
set( NJOY21_Clang_Linux_coverage_flags "--coverage" )
set( NJOY21_Clang_Linux_subproject_flags  )
set( NJOY21_Clang_Linux_base_project_flags  )
set( NJOY21_Clang_Linux_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( NJOY21_Clang_Linux_link_time_optimization_flags "-flto" )
set( NJOY21_Clang_Linux_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( NJOY21_Clang_Linux_nonportable_optimization_flags "-march=native" )
set( NJOY21_Clang_Linux_static_flags "-static" )
set( NJOY21_Clang_Windows_common_flags "-stdlib=libc++" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( NJOY21_Clang_Windows_DEBUG_flags "-O0" "-g" "-gdwarf-3" )
set( NJOY21_Clang_Windows_RELEASE_flags "-O3" "-DNDEBUG" )
set( NJOY21_Clang_Windows_strict_flags "-Werror" )
set( NJOY21_Clang_Windows_coverage_flags "--coverage" )
set( NJOY21_Clang_Windows_subproject_flags  )
set( NJOY21_Clang_Windows_base_project_flags  )
set( NJOY21_Clang_Windows_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( NJOY21_Clang_Windows_link_time_optimization_flags "-flto" )
set( NJOY21_Clang_Windows_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( NJOY21_Clang_Windows_nonportable_optimization_flags "-march=native" )
set( NJOY21_Clang_Windows_static_flags "-static" )
set( NJOY21_GNU_Darwin_common_flags "-Wno-subobject-linkage" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( NJOY21_GNU_Darwin_DEBUG_flags "-O0" "-g" "-gdwarf-3" "-fsignaling-nans" )
set( NJOY21_GNU_Darwin_RELEASE_flags "-O3" "-DNDEBUG" )
set( NJOY21_GNU_Darwin_strict_flags "-Werror" )
set( NJOY21_GNU_Darwin_coverage_flags "--coverage" )
set( NJOY21_GNU_Darwin_subproject_flags  )
set( NJOY21_GNU_Darwin_base_project_flags  )
set( NJOY21_GNU_Darwin_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( NJOY21_GNU_Darwin_link_time_optimization_flags "-flto" )
set( NJOY21_GNU_Darwin_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( NJOY21_GNU_Darwin_nonportable_optimization_flags "-march=native" )
set( NJOY21_GNU_Darwin_static_flags "-static" )
set( NJOY21_GNU_Linux_common_flags "-Wno-subobject-linkage" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( NJOY21_GNU_Linux_DEBUG_flags "-O0" "-g" "-gdwarf-3" "-fsignaling-nans" )
set( NJOY21_GNU_Linux_RELEASE_flags "-O3" "-DNDEBUG" )
set( NJOY21_GNU_Linux_strict_flags "-Werror" )
set( NJOY21_GNU_Linux_coverage_flags "--coverage" )
set( NJOY21_GNU_Linux_subproject_flags  )
set( NJOY21_GNU_Linux_base_project_flags  )
set( NJOY21_GNU_Linux_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( NJOY21_GNU_Linux_link_time_optimization_flags "-flto" )
set( NJOY21_GNU_Linux_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( NJOY21_GNU_Linux_nonportable_optimization_flags "-march=native" )
set( NJOY21_GNU_Linux_static_flags "-static" )
set( NJOY21_GNU_Windows_common_flags "-Wno-subobject-linkage" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( NJOY21_GNU_Windows_DEBUG_flags "-O0" "-g" "-gdwarf-3" "-fsignaling-nans" )
set( NJOY21_GNU_Windows_RELEASE_flags "-O3" "-DNDEBUG" )
set( NJOY21_GNU_Windows_strict_flags "-Werror" )
set( NJOY21_GNU_Windows_coverage_flags "--coverage" )
set( NJOY21_GNU_Windows_subproject_flags  )
set( NJOY21_GNU_Windows_base_project_flags  )
set( NJOY21_GNU_Windows_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( NJOY21_GNU_Windows_link_time_optimization_flags "-flto" )
set( NJOY21_GNU_Windows_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( NJOY21_GNU_Windows_nonportable_optimization_flags "-march=native" )
set( NJOY21_GNU_Windows_static_flags "-static" )
set( NJOY21_AppleClang_Darwin_common_flags "-stdlib=libc++" "-Wall" "-Wextra" "-Wpedantic" "-std=c++14" )
set( NJOY21_AppleClang_Darwin_DEBUG_flags "-O0" "-g" "-gdwarf-3" )
set( NJOY21_AppleClang_Darwin_RELEASE_flags "-O3" "-DNDEBUG" )
set( NJOY21_AppleClang_Darwin_strict_flags "-Werror" )
set( NJOY21_AppleClang_Darwin_coverage_flags "--coverage" )
set( NJOY21_AppleClang_Darwin_subproject_flags  )
set( NJOY21_AppleClang_Darwin_base_project_flags  )
set( NJOY21_AppleClang_Darwin_profile_generate_flags "-fprofile-generate='${CMAKE_BINARY_DIR}/profiling'" )
set( NJOY21_AppleClang_Darwin_link_time_optimization_flags "-flto" )
set( NJOY21_AppleClang_Darwin_profile_use_flags "-fprofile-use='${CMAKE_BINARY_DIR}/profiling'" )
set( NJOY21_AppleClang_Darwin_nonportable_optimization_flags "-march=native" )
set( NJOY21_AppleClang_Darwin_static_flags "-static" )

if ( static_NJOY21 )
    set( NJOY21_library_linkage STATIC )
else ()
    set( NJOY21_library_linkage SHARED )
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

if( NOT TARGET njoy )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/njoy )
endif()

if( NOT TARGET hana-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/hana-adapter )
endif()

if( NOT TARGET fmt-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/fmt-adapter )
endif()

if( NOT TARGET catch-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/catch-adapter )
endif()

if( NOT TARGET dimwits )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/dimwits )
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

if( NOT TARGET utility )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/utility )
endif()

if( NOT TARGET njoy_c_bindings )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/njoy_c_bindings )
endif()

if( NOT TARGET tclap-adapter )
    add_subdirectory( ${ROOT_DIRECTORY}/subprojects/tclap-adapter )
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
message( STATUS "NJOY21" )
message( STATUS "Git current branch: ${GIT_BRANCH}" )
message( STATUS "Git commit hash: ${GIT_HASH}" )
message( STATUS "" )
message( STATUS "-----------------------------------------------------------" )

add_library( NJOY21 ${NJOY21_library_linkage} 
             "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
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
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GASPR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/Label.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/PURR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/RECONR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/UNRESR.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card10.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card11.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card12.hpp"
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
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card10/Tempd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card2/Iopt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card2/Iprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card2/Itype.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card2/Nxtra.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card2/Suff.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card3/Hk.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card4/Izaw.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card5/Tempd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card6/Iopp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card6/Newfor.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card7/Thin1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card7/Thin2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card7/Thin3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card8/Tempd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card8/Tname.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card8a/Iza01.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card8a/Iza02.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card9/Emax.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card9/Ielas.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card9/Iwt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card9/Mte.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card9/Mti.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card9/Nbint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/ACER/Card9/Nmix.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/common.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/primitive.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/common/Matd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/common/Nin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/argument/common/Nout.hpp"
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
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GASPR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GASPR/Card1/Nendf.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GASPR/Card1/Nin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GASPR/Card1/Nout.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card1/Nendf.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card1/Ngout1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card1/Ngout2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card1/Npend.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Igg.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Ign.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Iprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Iwt.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Lord.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Matb.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Nsigz.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card2/Ntemp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/GROUPR/Card3/Title.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card4.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card5.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card1/Nendf.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card1/Nin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card1/Nout.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card1/Nplot.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card2/Iprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card2/Local.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card2/Npk.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card2/Nqa.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/HEATR/Card2/Ntemp.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER/Card1.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER/Card3.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER/Card1/Nin.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER/Card1/Nout.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER/Card2/Tapeid.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER/Card3/Matd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/MODER/Card3/Nin.hpp"
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
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/UNRESR/Card2.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/input/UNRESR/Card2/Iprint.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/io/Manager.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/io/Manager/Builder.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/io/Manager/FileGaurd.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/io/Manager/FortranOutput.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/legacy/Sequence.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/legacy/Sequence/Factory.hpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/src/njoy21/legacy/Sequence/routines.hpp" )

target_include_directories( NJOY21 PUBLIC src )

set( PREFIX NJOY21_${CMAKE_CXX_COMPILER_ID}_${CMAKE_SYSTEM_NAME} )

target_compile_options( NJOY21 PRIVATE 
${${PREFIX}_common_flags}
$<$<BOOL:${NJOY21_strict}>:${${PREFIX}_NJOY21_strict_flags}>
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
${CXX_appended_flags} ${NJOY21_appended_flags} )

target_link_libraries( NJOY21 PUBLIC "$<$<AND:$<CONFIG:RELEASE>,$<BOOL:${link_time_optimization}>>:${${PREFIX}_RELEASE_flags};${${PREFIX}_link_time_optimization_flags}$<$<BOOL:${profile_generate}>:${${PREFIX}_profile_generate_flags};>$<$<BOOL:${profile_use}>:${${PREFIX}_profile_use_flags};>$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags};>>$<$<CONFIG:DEBUG>:$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags};>>$<$<BOOL:CXX_appended_flags>:${CXX_appended_flags};>$<$<BOOL:NJOY21_appended_flags>:${NJOY21_appended_flags};>" )

target_link_libraries( NJOY21 PUBLIC dimwits PUBLIC tclap-adapter PUBLIC njoy_c_bindings PUBLIC Log PUBLIC utility )

if ( NOT is_subproject )
    add_executable( NJOY21_executable src/main.cpp )
    set_target_properties( NJOY21_executable PROPERTIES OUTPUT_NAME NJOY21 )
    target_compile_options( NJOY21_executable PRIVATE 
    ${${PREFIX}_common_flags}
    $<$<BOOL:${NJOY21_strict}>:${${PREFIX}_NJOY21_strict_flags}>
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
    ${CXX_appended_flags} ${NJOY21_appended_flags} )
    target_link_libraries( NJOY21_executable PUBLIC NJOY21 )
endif()

if( NOT is_subproject )
    enable_testing() 
    if ( unit_tests )
        add_subdirectory( src/njoy21/input/RECONR/Card4/Tempr/test )
        add_subdirectory( src/njoy21/input/BROADR/Card1/Nout/test )
        add_subdirectory( src/njoy21/input/Label/test )
        add_subdirectory( src/njoy21/input/RECONR/Card1/Npend/test )
        add_subdirectory( src/njoy21/input/RECONR/Card4/test )
        add_subdirectory( src/njoy21/input/ACER/Card4/Izaw/test )
        add_subdirectory( src/njoy21/input/ACER/Card1/Nendf/test )
        add_subdirectory( src/njoy21/input/GROUPR/test )
        add_subdirectory( src/njoy21/input/argument/primitive/Required/test )
        add_subdirectory( src/njoy21/input/RECONR/Card2/Tlabel/test )
        add_subdirectory( src/njoy21/input/ACER/Card12/test )
        add_subdirectory( src/njoy21/input/PURR/Card2/Ntemp/test )
        add_subdirectory( src/njoy21/input/PURR/Card2/test )
        add_subdirectory( src/njoy21/input/RECONR/test )
        add_subdirectory( src/njoy21/input/HEATR/Card1/Nout/test )
        add_subdirectory( src/njoy21/input/Card/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card3/Title/test )
        add_subdirectory( src/njoy21/input/RECONR/Card6/test )
        add_subdirectory( src/njoy21/input/ACER/Card9/Mte/test )
        add_subdirectory( src/njoy21/input/ACER/Card6/Iopp/test )
        add_subdirectory( src/njoy21/input/ACER/Card9/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Ntemp/test )
        add_subdirectory( src/njoy21/input/ACER/Card3/Hk/test )
        add_subdirectory( src/njoy21/input/ACER/Card1/Ngend/test )
        add_subdirectory( src/njoy21/input/ACER/Card8/test )
        add_subdirectory( src/njoy21/input/MODER/Card1/test )
        add_subdirectory( src/njoy21/input/GASPR/test )
        add_subdirectory( src/njoy21/input/BROADR/Card2/Ntemp2/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Igg/test )
        add_subdirectory( src/njoy21/input/BROADR/Card2/test )
        add_subdirectory( src/njoy21/input/GASPR/Card1/Nout/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Nsigz/test )
        add_subdirectory( src/njoy21/input/argument/primitive/Discriminating/test )
        add_subdirectory( src/njoy21/input/GASPR/Card1/Nendf/test )
        add_subdirectory( src/njoy21/input/UNRESR/Card2/Iprint/test )
        add_subdirectory( src/njoy21/input/ACER/Card7/Thin3/test )
        add_subdirectory( src/njoy21/input/ACER/Card1/Nace/test )
        add_subdirectory( src/njoy21/input/PURR/Card4/Sigz/test )
        add_subdirectory( src/njoy21/input/ACER/Card9/Nmix/test )
        add_subdirectory( src/njoy21/input/MODER/Card3/Matd/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card1/Npend/test )
        add_subdirectory( src/njoy21/input/RECONR/Card1/test )
        add_subdirectory( src/njoy21/input/RECONR/Card4/Errmax/test )
        add_subdirectory( src/njoy21/input/ACER/Card1/Npend/test )
        add_subdirectory( src/njoy21/input/BROADR/Card5/Mat1/test )
        add_subdirectory( src/njoy21/input/argument/primitive/Type/test )
        add_subdirectory( src/njoy21/input/PURR/Card1/Nendf/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card1/Ngout1/test )
        add_subdirectory( src/njoy21/input/ACER/Card2/Suff/test )
        add_subdirectory( src/njoy21/input/argument/primitive/Optional/test )
        add_subdirectory( src/njoy21/input/BROADR/Card4/Temp2/test )
        add_subdirectory( src/njoy21/input/ACER/Card9/Mti/test )
        add_subdirectory( src/njoy21/input/HEATR/Card1/Nendf/test )
        add_subdirectory( src/njoy21/input/RECONR/Card6/Enode/test )
        add_subdirectory( src/njoy21/input/RECONR/Card5/Cards/test )
        add_subdirectory( src/njoy21/input/ACER/Card8a/test )
        add_subdirectory( src/njoy21/input/PURR/Card3/Temp/test )
        add_subdirectory( src/njoy21/input/MODER/Card1/Nin/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Iprint/test )
        add_subdirectory( src/njoy21/input/HEATR/Card1/test )
        add_subdirectory( src/njoy21/input/BROADR/Card3/Errmax/test )
        add_subdirectory( src/njoy21/input/BROADR/Card1/Nin/test )
        add_subdirectory( src/njoy21/input/ACER/Card2/Iprint/test )
        add_subdirectory( src/njoy21/input/RECONR/Card3/Mat/test )
        add_subdirectory( src/njoy21/input/BROADR/Card3/Thnmax/test )
        add_subdirectory( src/njoy21/input/GASPR/Card1/test )
        add_subdirectory( src/njoy21/input/BROADR/Card1/Nendf/test )
        add_subdirectory( src/njoy21/input/RECONR/Card1/Nendf/test )
        add_subdirectory( src/njoy21/Driver/test )
        add_subdirectory( src/njoy21/input/GASPR/Card1/Nin/test )
        add_subdirectory( src/njoy21/input/ACER/Card2/Iopt/test )
        add_subdirectory( src/njoy21/input/RECONR/Card5/test )
        add_subdirectory( src/njoy21/input/UNRESR/test )
        add_subdirectory( src/njoy21/input/BROADR/Card3/Errthn/test )
        add_subdirectory( src/njoy21/input/ACER/Card1/Ndir/test )
        add_subdirectory( src/njoy21/input/ACER/Card9/Iwt/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card1/test )
        add_subdirectory( src/njoy21/input/MODER/Card3/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/test )
        add_subdirectory( src/njoy21/input/argument/primitive/Defaulted/test )
        add_subdirectory( src/njoy21/input/BROADR/Card2/Temp1/test )
        add_subdirectory( src/njoy21/input/ACER/Card10/test )
        add_subdirectory( src/njoy21/input/ACER/Card6/Newfor/test )
        add_subdirectory( src/njoy21/input/argument/Type/test )
        add_subdirectory( src/njoy21/input/ACER/Card8/Tname/test )
        add_subdirectory( src/njoy21/input/RECONR/Card3/Ngrid/test )
        add_subdirectory( src/njoy21/input/MODER/Card3/Nin/test )
        add_subdirectory( src/njoy21/input/BROADR/Card2/Istart/test )
        add_subdirectory( src/njoy21/input/ACER/Card5/Tempd/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Iwt/test )
        add_subdirectory( src/njoy21/input/ACER/Card6/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Ign/test )
        add_subdirectory( src/njoy21/input/PURR/Card4/test )
        add_subdirectory( src/njoy21/input/PURR/test )
        add_subdirectory( src/njoy21/input/argument/test )
        add_subdirectory( src/njoy21/input/UNRESR/Card2/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Lord/test )
        add_subdirectory( src/njoy21/input/ACER/Card5/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card1/Nendf/test )
        add_subdirectory( src/njoy21/input/RECONR/Card4/Err/test )
        add_subdirectory( src/njoy21/input/ACER/Card9/Nbint/test )
        add_subdirectory( src/njoy21/input/BROADR/Card1/test )
        add_subdirectory( src/njoy21/input/PURR/Card2/Nbin/test )
        add_subdirectory( src/njoy21/input/ACER/Card7/Thin1/test )
        add_subdirectory( src/njoy21/io/Manager/test )
        add_subdirectory( src/njoy21/input/BROADR/Card3/Errint/test )
        add_subdirectory( src/njoy21/input/PURR/Card2/Nsigz/test )
        add_subdirectory( src/njoy21/input/PURR/Card1/test )
        add_subdirectory( src/njoy21/input/BROADR/Card2/Mat1/test )
        add_subdirectory( src/njoy21/input/ACER/Card1/test )
        add_subdirectory( src/njoy21/input/ACER/Card7/test )
        add_subdirectory( src/njoy21/input/ACER/Card2/Nxtra/test )
        add_subdirectory( src/njoy21/input/ACER/Card9/Emax/test )
        add_subdirectory( src/njoy21/input/MODER/test )
        add_subdirectory( src/njoy21/input/ACER/Card4/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card1/Ngout2/test )
        add_subdirectory( src/njoy21/input/PURR/Card2/Nladr/test )
        add_subdirectory( src/njoy21/input/ACER/Card8a/Iza01/test )
        add_subdirectory( src/njoy21/input/PURR/Card2/Nunx/test )
        add_subdirectory( src/njoy21/input/MODER/Card2/test )
        add_subdirectory( src/njoy21/input/ACER/Card3/test )
        add_subdirectory( src/njoy21/input/ACER/Card7/Thin2/test )
        add_subdirectory( src/njoy21/input/BROADR/test )
        add_subdirectory( src/njoy21/input/BROADR/Card4/test )
        add_subdirectory( src/njoy21/input/ACER/Card9/Ielas/test )
        add_subdirectory( src/njoy21/input/RECONR/Card4/Errint/test )
        add_subdirectory( src/njoy21/input/ACER/Card10/Tempd/test )
        add_subdirectory( src/njoy21/input/ACER/Card8a/Iza02/test )
        add_subdirectory( src/njoy21/input/PURR/Card2/Iprint/test )
        add_subdirectory( src/njoy21/input/RECONR/Card3/Ncards/test )
        add_subdirectory( src/njoy21/input/BROADR/Card2/Istrap/test )
        add_subdirectory( src/njoy21/input/PURR/Card3/test )
        add_subdirectory( src/njoy21/input/HEATR/Card1/Nplot/test )
        add_subdirectory( src/njoy21/input/ACER/test )
        add_subdirectory( src/njoy21/input/HEATR/Card1/Nin/test )
        add_subdirectory( src/njoy21/legacy/Sequence/test )
        add_subdirectory( src/njoy21/input/ACER/Card11/test )
        add_subdirectory( src/njoy21/CommandLine/test )
        add_subdirectory( src/njoy21/input/BROADR/Card5/test )
        add_subdirectory( src/njoy21/input/RECONR/Card3/test )
        add_subdirectory( src/njoy21/input/ACER/Card8/Tempd/test )
        add_subdirectory( src/njoy21/input/RECONR/Card2/test )
        add_subdirectory( src/njoy21/input/BROADR/Card3/test )
        add_subdirectory( src/njoy21/input/MODER/Card2/Tapeid/test )
        add_subdirectory( src/njoy21/input/ACER/Card2/Itype/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card3/test )
        add_subdirectory( src/njoy21/input/MODER/Card1/Nout/test )
        add_subdirectory( src/njoy21/input/GROUPR/Card2/Matb/test )
        add_subdirectory( src/njoy21/input/ACER/Card2/test )
    endif() 
endif()

set( installation_targets NJOY21 )
if ( NOT is_subproject )
    list( APPEND installation_targets NJOY21_executable )
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
