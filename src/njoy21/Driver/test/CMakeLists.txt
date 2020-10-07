
add_executable( njoy21.Driver.test Driver.test.cpp )
target_compile_options( njoy21.Driver.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${njoy21_appended_flags} )
file( GLOB resources "resources/*" )
foreach( resource ${resources})
    file( COPY "${resource}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}" )
endforeach()
target_include_directories( njoy21.Driver.test
    PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/src/
          src/
    )
target_link_libraries( njoy21.Driver.test
    PUBLIC ENDFtk
    PUBLIC RECONR
    PUBLIC tclap-adapter
    PUBLIC njoy_c_bindings
    PUBLIC lipservice
    PUBLIC dimwits
    PUBLIC utility
    )
add_test( NAME njoy21.Driver COMMAND njoy21.Driver.test )
