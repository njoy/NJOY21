public:

class Builder{
  optional<std::string> inputPath;    
  optional<std::string> outputPath;

public:
  Builder& input( const std::string& path ){
    this->inputPath = path; return *this;
  }

  const optional<std::string>& input() const {
    return this->inputPath;
  }

  Builder& output( const std::string& path ){
    this->outputPath = path; return *this;
  }

  const optional<std::string>& output() const {
    return this->outputPath;
  }

  Manager construct() {
    auto input = []( auto& input ){
      if ( not input ){ return input::iRecordStream< char >( std::cin ); }
      auto stream = std::ifstream( input->c_str() );
      if ( not stream.good() ){
        Log::error( "Could not open input file" );
        Log::info( "Specified input path: {}", *(input) );
        throw std::exception();
      }
      return input::iRecordStream< char >( std::move(stream) );
    };

    return Manager( input( this->inputPath ), std::move( this->outputPath ) );
  }
};
