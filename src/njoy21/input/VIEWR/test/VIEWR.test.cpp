#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Parsing valid VIEWR input" ){
  { 
    iRecordStream<char> iss( std::istringstream( "21 22" ) );
    VIEWR viewr( iss );
    REQUIRE( viewr.card1.infile.value == 21 );
    REQUIRE( viewr.card1.nps.value == 22 );
  }
}

SCENARIO( "Parsing invalid VIEWR input" ){
  {
    iRecordStream<char> iss( std::istringstream( "21 -21" ) );
    REQUIRE_THROWS( VIEWR( iss ) );
  }
  {
    iRecordStream<char> iss( std::istringstream( "21 -22" ) );
    REQUIRE_THROWS( VIEWR( iss ) );
  } 
  {
    iRecordStream<char> iss( std::istringstream( "1 22" ) );
    REQUIRE_THROWS( VIEWR( iss ) );
  }
}
