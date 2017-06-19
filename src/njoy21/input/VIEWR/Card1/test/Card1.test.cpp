#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Parsing valid VIEWR Card1 input" ){
  { 
    iRecordStream<char> iss( std::istringstream( "21 22" ) );
    VIEWR::Card1 card1( iss );
    REQUIRE( card1.infile.value == 21 );
    REQUIRE( card1.nps.value == 22 );
  }
  {
    iRecordStream<char> iss( std::istringstream( "21 -22") );
    VIEWR::Card1 card1( iss );
    REQUIRE( card1.infile.value == 21 );
    REQUIRE( card1.nps.value == -22 );
  } 	
}

SCENARIO( "Parsing invalid VIEWR Card1 input" ){
  {
    iRecordStream<char> iss( std::istringstream( "21 -21" ) );
    REQUIRE_THROWS( VIEWR::Card1( iss ) );
  }
  {
    iRecordStream<char> iss( std::istringstream( "1 22" ) );
    REQUIRE_THROWS( VIEWR::Card1( iss ) );
  }
}
