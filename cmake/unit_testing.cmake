#######################################################################
# Setup
#######################################################################

message( STATUS "Adding NJOY21 unit testing" )
enable_testing()


#######################################################################
# Unit testing directories
#######################################################################

add_subdirectory( src/njoy21/CommandLine/test )
add_subdirectory( src/njoy21/Driver/test )
add_subdirectory( src/njoy21/Version/test )
add_subdirectory( src/njoy21/io/Manager/test )
add_subdirectory( src/njoy21/legacy/Sequence/test )
add_subdirectory( src/njoy21/modern/Sequence/test )
