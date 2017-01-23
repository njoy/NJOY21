class Manager {
  
  input::iRecordStream< char > inputStream;
  optional<std::string> outputPath;
  utility::stream::TemporaryFileStream legacyBuffer;

  bool openedBuffer = false;

protected:
  
  Manager( input::iRecordStream< char >&& input,
	   optional< std::string >&& outputPath ) :
    inputStream( std::move(input) ),
    outputPath( std::move(outputPath) ),
    legacyBuffer( utility::stream::TemporaryFileStream() ){}
 
#include "njoy21/io/Manager/Builder.hpp"
#include "njoy21/io/Manager/FileGaurd.hpp"

public:

  input::iRecordStream< char >&
  input(){ return this->inputStream; }

  FileGaurd
  output( legacy::Sequence* ){
    if ( not this->openedBuffer ){
      auto bufferPath = this->legacyBuffer.filename();
      this->legacyBuffer.flush();
      njoy_setup_input_file( &( bufferPath[0] ), bufferPath.length() );   
    }
    
    if ( not this->outputPath ) return FileGaurd();
    return FileGaurd( *outputPath );
  }

  std::unique_ptr< std::ostream >
  output( modern::Sequence* ){
    return ( not this->outputPath ) ?
      std::make_unique< std::ostream >( std::cout.rdbuf() ) :
      std::make_unique< std::ofstream >( *this->outputPath, std::ios_base::app );
  }

  std::ostream& buffer(){ return this->legacyBuffer; }
  
};
