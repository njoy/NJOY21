FileGaurd output( legacy::Sequence* ){
  if ( not this->openedBuffer ){
    auto bufferPath = this->legacyBuffer.filename();
    this->legacyBuffer.flush();
    njoy_setup_input_file( &( bufferPath[0] ), bufferPath.length() );   
  }
  
  if ( not this->outputPath ) return FileGaurd();
  return FileGaurd( *outputPath );
}

std::unique_ptr< std::ostream > output( modern::Sequence* ){
  return ( not this->outputPath ) ?
    std::make_unique< std::ostream >( std::cout.rdbuf() ) :
    std::make_unique< std::ofstream >( 
        *this->outputPath, std::ios_base::app );
}

