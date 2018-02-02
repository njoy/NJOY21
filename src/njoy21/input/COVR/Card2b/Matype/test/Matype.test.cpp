#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "matype output values",
  "[COVR], [Card2b], [Matype]"){
  GIVEN( "valid inputs for matype" ){
    WHEN( "the matype value is provided" ){
      THEN( "the returned class has the correct tape value" ){
        for( auto& matype : {3, 4} ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( matype ) ) );
          REQUIRE( matype == argument::extract< 
            COVR::Card2b::Matype >( iss ).value );
        }
      } // THEN
    } // WHEN

    WHEN( "no matype value given " ){
      iRecordStream<char> iss( std::istringstream( "  /" ) );

      THEN( "default value is substituted in" ){
        REQUIRE( 3 == argument::extract< COVR::Card2b::Matype > ( iss ).value );
      } // THEN
    } // WHEN
  
    WHEN( "matype tapes are out of range" ){
      THEN( "an exception is thrown" ){
        for( auto& matype : {1, 2, 5, 6} ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( matype ) ) );
          REQUIRE_THROWS( argument::extract< COVR::Card2b::Matype>( iss ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

