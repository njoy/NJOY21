static io::Manager setupManager( CommandLine& commandLine ){
  io::Manager::Builder builder;
  if( commandLine.signature ){
    njoy::Log::info( "signature: {}", Signature::signature );
    return builder.construct();
  }

  if ( commandLine.inputPath ){
    builder.input( *(commandLine.inputPath) );
  }
  if ( commandLine.outputPath ){
    builder.output( *(commandLine.outputPath) );
  }
  return builder.construct();      
}
