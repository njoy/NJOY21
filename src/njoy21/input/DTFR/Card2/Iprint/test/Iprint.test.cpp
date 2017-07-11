#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR iprint values",
  "[DTFR],[Card2], [Iprint]"){

  GIVEN( "valid iprint values" ){
    iRecordStream<char> iss1( std::istringstream( "0" ) );
    iRecordStream<char> iss2( std::istringstream( "1" ) );
    
    THEN( "the returned class has the correct value" ){
      REQUIRE( 0 == argument::extract< DTFR::Card2::Iprint >( iss1 ).value );
      REQUIRE( 1 == argument::extract< DTFR::Card2::Iprint >( iss2 ).value );

    } // THEN
  } // GIVEN
  
  GIVEN( "invalid iprint values" ){
    iRecordStream<char> iss1( std::istringstream( "-1" ) );
    iRecordStream<char> iss2( std::istringstream( "2"  ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( argument::extract< DTFR::Card2::Iprint >( iss1 ) );
      REQUIRE_THROWS( argument::extract< DTFR::Card2::Iprint >( iss2 ) );
    } // THEN
  } // GIVEN
} // SCENARIO
