static Directory setupLegacyDirectory( CommandLine& commandLine ){
  return ( commandLine.legacySwitch ) ?
    Directory( { "MODER", "RECONR", "BROADR", "PURR", "UNRESR", "ACER",
                  "GASPR", "HEATR", "GROUPR", "VIEWR", "MIXR", "DTFR",
                  "THERMR", "RESXSR", "MATXSR", "GAMINR", "PLOTR",
                  "COVR", "WIMSR", "POWR", "CCCCR", "ERRORR" } ):
    Directory( { "MODER", "RECONR", "BROADR", "PURR", "UNRESR", "ACER",
                  "GASPR", "HEATR", "GROUPR", "VIEWR", "MIXR", "DTFR",
                  "THERMR", "LEAPR", "RESXSR", "MATXSR", "GAMINR", "PLOTR",
                  "COVR", "WIMSR", "POWR", "CCCCR", "ERRORR" } );
}
