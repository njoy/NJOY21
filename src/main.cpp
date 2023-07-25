#include "njoy21.hpp"

using namespace njoy::njoy21;

int main( int argc, char* argv[] ){
  try{
    Driver driver( argc, argv );
    driver();
  } catch( std::exception& ex ){
    njoy::Log::info( "Error while running NJOY21:");
    njoy::Log::info( "\t{}", ex.what() );
    return 1;
  }
}
