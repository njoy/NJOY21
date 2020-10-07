
add_executable( njoy21.CommandLine.test CommandLine.test.cpp )
target_compile_options( njoy21.CommandLine.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${njoy21_appended_flags} )
target_include_directories( njoy21.CommandLine.test
    PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/src/
          src/
    )
target_link_libraries( njoy21.CommandLine.test
    PUBLIC ENDFtk
    PUBLIC RECONR
    PUBLIC tclap-adapter
    PUBLIC njoy_c_bindings
    PUBLIC lipservice
    PUBLIC dimwits
    PUBLIC utility
    )
add_test( NAME njoy21.CommandLine COMMAND njoy21.CommandLine.test )
