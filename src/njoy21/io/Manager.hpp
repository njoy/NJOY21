class Manager {
  
  lipservice::iRecordStream< char > inputStream;
  std::optional<std::string> outputPath;
  std::optional<std::string> errorPath;
  utility::stream::TemporaryFileStream legacyBuffer;

  bool openedBuffer = false;

protected:
  
  Manager( lipservice::iRecordStream< char >&& input,
           std::optional< std::string >&& outputPath,
           std::optional< std::string >&& errorPath ) :
    inputStream( std::move(input) ),
    outputPath( std::move(outputPath) ),
    errorPath( std::move(errorPath) ),
    legacyBuffer( utility::stream::TemporaryFileStream() ){}
 
public:

#include "njoy21/io/Manager/Builder.hpp"
#include "njoy21/io/Manager/FileGuard.hpp"


  lipservice::iRecordStream< char >&
  input(){ return this->inputStream; }

#include "njoy21/io/Manager/src/output.hpp"

  std::ostream& buffer(){ return this->legacyBuffer; }
  
};
