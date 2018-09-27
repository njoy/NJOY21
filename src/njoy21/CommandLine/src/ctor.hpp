CommandLine( int argc, char* argv[] ){
  TCLAP::ValueArg< optional< std::string > >
    inputPath( "i", "input",                                                         
  "path to file providing NJOY21 input. (defaults to standard input)",
  false, optional< std::string >(), "path" );

  TCLAP::ValueArg< optional< std::string > >
    outputPath( "o", "output",                                                         
    "path to file where NJOY21 output ought to be directed. (defaults to standard output)",
    false, optional< std::string >(), "path" );

  TCLAP::SwitchArg
    legacySwitch( "L", "legacy",
      "Call to Fortran routines even if C++ routines are available" );

  TCLAP::SwitchArg
    verifyOnly( "v", "verify-only",
    "Verify the input deck without executing commands" );

  TCLAP::CmdLine cmd("NJOY21: NJOY for the 21st Century", 
                      ' ', 
                      Version::version );
  cmd.add( inputPath );
  cmd.add( outputPath );
  cmd.add( legacySwitch );
  cmd.add( verifyOnly );
  try{ cmd.parse( argc, argv ); } catch ( TCLAP::ArgException& e ){
    Log::error("{} for argument {}", e.error(), e.argId() );
    throw std::exception();
  }
  this->inputPath = inputPath.getValue();
  this->outputPath = outputPath.getValue();
  this->legacySwitch = legacySwitch.getValue();
  this->verifyOnly = verifyOnly.getValue();
}

