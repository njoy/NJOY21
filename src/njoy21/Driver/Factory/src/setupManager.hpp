static io::Manager setupManager( CommandLine& commandLine ){
  io::Manager::Builder builder;

  if ( commandLine.inputPath ){
    builder.input( *(commandLine.inputPath) );
  }
  if ( commandLine.outputPath ){
    builder.output( *(commandLine.outputPath) );
  }
  if ( commandLine.errorPath ){
    builder.error( *(commandLine.errorPath) );
  }
  return builder.construct();      
}
