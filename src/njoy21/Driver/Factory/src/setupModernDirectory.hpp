static Directory setupModernDirectory( CommandLine& commandLine ){
  return ( commandLine.legacySwitch ) ? 
    Directory() : 
    Directory( { "RECONR", "LEAPR" } );
}
