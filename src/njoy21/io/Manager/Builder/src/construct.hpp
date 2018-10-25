Manager construct() {
  auto input = []( auto& input ){
    if ( not input ){ return lipservice::iRecordStream< char >( std::cin ); }

    auto stream = std::ifstream( input->c_str() );
    if ( not stream.good() ){
      Log::error( "Could not open input file" );
      Log::info( "Specified input path: {}", *(input) );
      throw std::exception();
    }
    return lipservice::iRecordStream< char >( std::move(stream) );
  };

  return Manager( input( this->inputPath ), std::move( this->outputPath ) );
}

