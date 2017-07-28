#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card4 isabt values",
  "[LEAPR], [Card4], [Isabt]"){

  GIVEN( "valid isabt values" ){
    iRecordStream<char> iss0( std::istringstream( "0" ) );
    iRecordStream<char> iss1( std::istringstream( "1" ) );
    THEN( "the returned calss has the correct value" ){
      REQUIRE( 0 == argument::extract< LEAPR::Card4::Isabt >( iss0 ).value );
      REQUIRE( 1 == argument::extract< LEAPR::Card4::Isabt >( iss1 ).value );
    } // THEN
  } // GIVEN

  GIVEN( "no isabt value" ){
    iRecordStream<char> iss( std::istringstream( " /" ) );
    THEN( "The default value is substituted in" ){
      REQUIRE( 0 == argument::extract< LEAPR::Card4::Isabt >( iss ).value );
    } // THEN 
  } // GIVEN

  GIVEN( "invalid isabt values" ){
    iRecordStream<char> iss1( std::istringstream( "-1" ) );
    iRecordStream<char> iss2( std::istringstream( "2"  ) );
    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( argument::extract< LEAPR::Card4::Isabt >( iss1 ) );
      REQUIRE_THROWS( argument::extract< LEAPR::Card4::Isabt >( iss2 ) );
    } // THEN
  } // GIVEN
} // SCENARIO
