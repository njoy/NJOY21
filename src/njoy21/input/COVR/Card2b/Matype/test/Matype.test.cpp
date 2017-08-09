#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "matype output values",
  "[COVR], [Card2b], [Matype]"){
  GIVEN( "valid inputs for matype" ){
    WHEN( "the matype value is provided" ){
      std::vector<int> validValues{3, 4};
      THEN( "the returned class has the correct tape value" ){
        for( auto& matype : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( matype ) ) );
          REQUIRE( matype == argument::extract< 
            COVR::Card2b::Matype >( iss ).value );
        }
      } // THEN
    } // WHEN

    WHEN( "no matype value given " ){
      THEN( "default value is substituted in" ){
        iRecordStream<char> iss( std::istringstream( "  /" ) );
        REQUIRE( 3 == argument::extract<
          COVR::Card2b::Matype > ( iss ).value );
      } // THEN
    } // WHEN
  
    WHEN( "matype tapes are out of range" ){
      std::vector<int> invalidValues{1, 2, 5, 6};
      THEN( "an exception is thrown" ){
        for( auto& matype : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( matype ) ) );
          REQUIRE_THROWS( argument::extract<
            COVR::Card2b::Matype>( iss ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

