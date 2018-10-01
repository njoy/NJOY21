class Builder{
  optional<std::string> inputPath;    
  optional<std::string> outputPath;

public:
  Builder() = default;

  Builder( optional< std::string > input, optional< std::string > output ):
    inputPath( input ),
    outputPath( output )
  { }

  Builder& input( const std::string& path ){
    this->inputPath = path; 
    return *this;
  }

  const optional<std::string>& input() const {
    return this->inputPath;
  }

  Builder& output( const std::string& path ){
    this->outputPath = path; 
    return *this;
  }

  const optional<std::string>& output() const {
    return this->outputPath;
  }

#include "njoy21/io/Manager/Builder/src/construct.hpp"

};
