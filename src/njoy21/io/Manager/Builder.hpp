class Builder{
  optional<std::string> inputPath;    
  optional<std::string> outputPath;
  optional<std::string> errorPath;

public:
  Builder() = default;

  Builder( optional< std::string > input, 
           optional< std::string > output,
           optional< std::string > error ):
    inputPath( input ),
    outputPath( output ),
    errorPath( error )
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

  Builder& error( const std::string& path ){
    this->errorPath = path; 
    return *this;
  }

  const optional<std::string>& error() const {
    return this->errorPath;
  }

#include "njoy21/io/Manager/Builder/src/construct.hpp"

};
