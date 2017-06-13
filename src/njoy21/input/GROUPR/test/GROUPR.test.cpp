#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

std::string sCard1( "-30 -32 0 -34 /\n" );
std::string sCard3( "'GROUPR Card3 title for testing' /\n" );
std::string sCard4( "293.6 /\n" );
std::string sCard5( "1E-10 /\n" );

SCENARIO( "Parsing valid GROUPR input" ){
  WHEN( "reading in a very generic input" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 2 0 2 4 1 1 1 /"         // Card2
      + sCard3
      + sCard4
      + sCard5
      + "3 18 'MF3 MT18' /\n"         // Card 9.1
      + "3 102 'MF3 MT102' /\n"       // Card 9.2
      + "10 /\n"                      // Card 9.3
      + "0 /\n"                       // Card 9.4
      + "0 /\n"                       // Card10
    ) );
    THEN( "the input values can be verified" ){
      GROUPR groupr( iss );
    }
  }
}

SCENARIO( "Parsing invalid GROUPR input" ){
}
