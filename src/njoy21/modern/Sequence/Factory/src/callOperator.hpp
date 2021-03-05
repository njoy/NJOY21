std::unique_ptr< interface::Routine::Sequence >
operator()( std::string& label ){

  auto& input = manager.input();
  auto readBuffer = input.rdbuf();
  try {
    std::vector< std::unique_ptr< interface::Routine > > sequence;
    do {
      sequence.push_back( this->parse( label, input ) );
      input.rdbuf( readBuffer );

      label = lipservice::Label::extract( input );
    } while ( this->permittedRoutines.count( label ) );

    return std::make_unique< Sequence >
        ( Sequence( manager, std::move( sequence ) ) );
  } catch ( std::exception& e ){
    Log::info( "Error while calling the modern::Sequence::Factory" );
    Log::info( "\t{}", e.what() );

    input.rdbuf( readBuffer );
    throw e;
  }
}  

