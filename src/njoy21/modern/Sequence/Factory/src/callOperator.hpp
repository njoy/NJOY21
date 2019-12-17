std::unique_ptr< interface::Routine::Sequence >
operator()( std::string& label ){
  using TeeBuffer =
      utility::stream::basic_Tee_streambuf< utility::stream::InputTag, char >;

  auto& input = manager.input();
  auto readBuffer = input.rdbuf();
  try {
    std::vector< std::unique_ptr< interface::Routine > > sequence;
    do {
      TeeBuffer teeBuffer( readBuffer, manager.buffer().rdbuf() );
      input.rdbuf( &teeBuffer );
      sequence.push_back( this->parse( label, input ) );
      input.rdbuf( readBuffer );

      label = lipservice::Label::extract( input );
    } while ( this->permittedRoutines.count( label ) );

    return std::make_unique< Sequence >
        ( Sequence( manager, std::move( sequence ) ) );
  } catch ( std::exception& e ){
    input.rdbuf( readBuffer );
    throw e;
  }
}  

