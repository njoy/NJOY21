#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "epmin output values",
  "[COVR], [Card2a], [Epmin]"){

  GIVEN( "valid inputs for nin, nout, and npend" ){
    WHEN( "the epmin value is valid" ){
      std::vector<double> validValues{0.0, 1.0, 2.0};
      THEN( "the returned class has the correct tape value" ){
        for( auto& epmin : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( epmin ) ) );
          REQUIRE( epmin == argument::extract< 
            COVR::Card2a::Epmin >( iss ).value );
        }
      } // THEN
    } // WHEN

    WHEN( "no epmin value given " ){
      THEN( "default value is substituted in" ){
        iRecordStream<char> iss( std::istringstream( "  /" ) );
        REQUIRE( 0.0 == argument::extract<
          COVR::Card2a::Epmin > ( iss ).value );
      } // THEN
    } // WHEN
  
    WHEN( "epmin tapes are out of range" ){
      std::vector<double> invalidValues{-0.1, -1.0, -2.0};
      THEN( "an exception is thrown" ){
        for( auto& epmin : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( epmin ) ) );
          REQUIRE_THROWS( argument::extract<
            COVR::Card2a::Epmin>( iss ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

