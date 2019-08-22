std::pair< FileGuard, FileGuard > 
output( legacy::Sequence* ){
  if ( not this->openedBuffer ){
    auto bufferPath = this->legacyBuffer.filename();
    this->legacyBuffer.flush();
    njoy_setup_input_file( &( bufferPath[0] ), bufferPath.length() );   
  }

  auto outputGuard = this->outputPath 
      ? FileGuard( *outputPath, outputPolicy() ) 
      : FileGuard();

  if( this->errorPath == this->outputPath ){
    njoy_sync_error();
    return std::make_pair( std::move( outputGuard ), FileGuard{} );
  }

  auto errorGuard = this->errorPath 
      ? FileGuard( *errorPath, errorPolicy() ) 
      : FileGuard();

  return std::make_pair( std::move( outputGuard ), std::move( errorGuard ) );
}

std::pair< std::unique_ptr< std::ostream >, std::unique_ptr< std::ostream > >
output( modern::Sequence* ){
  auto outputStream = this->outputPath
    ? std::make_unique< std::ofstream >( *this->outputPath, std::ios_base::app )
    : std::make_unique< std::ostream >( std::cout.rdbuf() );
  auto errorStream = this->errorPath
    ? std::make_unique< std::ofstream >( *this->errorPath, std::ios_base::app )
    : std::make_unique< std::ostream >( std::cerr.rdbuf() );

  return std::make_pair( std::move( outputStream ), std::move( errorStream ) );
}
