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
    auto inputStream = []( auto& input ){
      return ( not input ) ?
      input::iRecordStream< char >( std::cin ) :
      input::iRecordStream< char >( std::ifstream( input->c_str() ) );
    };

    return Manager( inputStream( this->inputPath ),
		    std::move( this->outputPath ) );
  }
};
