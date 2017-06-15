#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Infile input values" ) {
  GIVEN( "valid infile tape values" ) {
  
    std::vector<int> validInfile{ 20, 50, 99 };
  
    THEN( "the returned class has a correct tape value" ) {
      for( int infile : validInfile ) {
        iRecordStream<char> iss( std::istringstream( std::to_string( infile ) ) );
        REQUIRE( argument::extract< VIEWR::Card1::Infile > (iss).value == infile );
      }
    }
  }
  GIVEN( "invalid infile tape values" ) {
	  
    std::vector<int> invalidInfile{ -19, 19, 100, -100 };
	  
      THEN( "throw an exception" ){
  	for( int infile : invalidInfile ) {
	  iRecordStream<char> iss( std::istringstream( std::to_string( infile ) ) );
  	  REQUIRE_THROWS( argument::extract< VIEWR::Card1::Infile > (iss) );
        }
      }
  }
}  
