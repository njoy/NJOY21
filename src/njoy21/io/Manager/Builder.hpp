class Builder{
  std::optional<std::string> inputPath;    
  std::optional<std::string> outputPath;
  std::optional<std::string> errorPath;

public:
  Builder() = default;

  Builder( std::optional< std::string > input, 
           std::optional< std::string > output,
           std::optional< std::string > error ):
    inputPath( input ),
    outputPath( output ),
    errorPath( error )
  { }

  Builder& input( const std::string& path ){
    this->inputPath = path; 
    return *this;
  }

  const std::optional<std::string>& input() const {
    return this->inputPath;
  }

  Builder& output( const std::string& path ){
    this->outputPath = path; 
    return *this;
  }

  const std::optional<std::string>& output() const {
    return this->outputPath;
  }

  Builder& error( const std::string& path ){
    this->errorPath = path; 
    return *this;
  }

  const std::optional<std::string>& error() const {
    return this->errorPath;
  }

#include "njoy21/io/Manager/Builder/src/construct.hpp"

};
