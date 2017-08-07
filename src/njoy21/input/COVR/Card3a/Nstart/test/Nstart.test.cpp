#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "nstart output values",
  "[COVR], [Card3a], [Nstart]"){
  GIVEN( "valid inputs for nstart" ){
    WHEN( "the nstart value is provided" ){
      std::vector<int> validValues{0, 2, 5};
      THEN( "the returned class has the correct tape value" ){
        for( auto& nstart : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( nstart ) ) );
          REQUIRE( nstart == argument::extract< 
            COVR::Card3a::Nstart >( iss ).value );
        }
      } // THEN
    } // WHEN

    WHEN( "no nstart value given " ){
      THEN( "default value is substituted in" ){
        iRecordStream<char> iss( std::istringstream( "  /" ) );
        REQUIRE( 1 == argument::extract<
          COVR::Card3a::Nstart > ( iss ).value );
      } // THEN
    } // WHEN
  
    WHEN( "nstart tapes are out of range" ){
      std::vector<int> invalidValues{-1, -2};
      THEN( "an exception is thrown" ){
        for( auto& nstart : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( nstart ) ) );
          REQUIRE_THROWS( argument::extract<
            COVR::Card3a::Nstart>( iss ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

