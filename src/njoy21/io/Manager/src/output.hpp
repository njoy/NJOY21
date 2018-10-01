FileGuard output( legacy::Sequence* ){
  if ( not this->openedBuffer ){
    auto bufferPath = this->legacyBuffer.filename();
    this->legacyBuffer.flush();
    njoy_setup_input_file( &( bufferPath[0] ), bufferPath.length() );   
  }
  
  if ( not this->outputPath ) return FileGuard();
  return FileGuard( *outputPath );
}

std::unique_ptr< std::ostream > output( modern::Sequence* ){
  return ( not this->outputPath ) ?
    std::make_unique< std::ostream >( std::cout.rdbuf() ) :
    std::make_unique< std::ofstream >( 
        *this->outputPath, std::ios_base::app );
}

