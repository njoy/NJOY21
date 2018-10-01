static io::Manager setupManager( CommandLine& commandLine ){
  io::Manager::Builder builder{ commandLine.inputPath, commandLine.outputPath };
  return builder.construct();      
}
