if ( NOT PYTHON_EXECUTABLE )
  find_package( PythonInterp )
  if ( NOT PYTHONINTERP_FOUND )
    message( FATAL_ERROR "Python interpeter installation was not found." )
  endif()
endif()

set( RESOURCES "${CMAKE_CURRENT_SOURCE_DIR}/resources" )

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/execute.py"
               "${CMAKE_CURRENT_BINARY_DIR}/execute.py" COPYONLY )

add_subdirectory( "01" )	     
add_subdirectory( "02" )
add_subdirectory( "03" )
add_subdirectory( "04" )
add_subdirectory( "05" )
add_subdirectory( "06" )
add_subdirectory( "07" )
