class Manager {
  
  lipservice::iRecordStream< char > inputStream;
  optional<std::string> outputPath;
  utility::stream::TemporaryFileStream legacyBuffer;

  bool openedBuffer = false;

protected:
  
  Manager( lipservice::iRecordStream< char >&& input,
	   optional< std::string >&& outputPath ) :
    inputStream( std::move(input) ),
    outputPath( std::move(outputPath) ),
    legacyBuffer( utility::stream::TemporaryFileStream() ){}
 
#include "njoy21/io/Manager/Builder.hpp"
#include "njoy21/io/Manager/FileGuard.hpp"

public:

  lipservice::iRecordStream< char >&
  input(){ return this->inputStream; }

#include "njoy21/io/Manager/src/output.hpp"

  std::ostream& buffer(){ return this->legacyBuffer; }
  
};
