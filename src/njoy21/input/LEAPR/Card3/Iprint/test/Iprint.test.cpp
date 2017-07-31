#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card3 iprint values",
  "[LEAPR], [Card3], [Iprint]"){

  GIVEN( "valid iprint values" ){
    WHEN( "iprint value is given" ){
      std::vector<int> validValues{0, 1, 2};
      THEN( "the returned class has the correct value" ){
        for( auto& iprint : validValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( iprint ) ) );
          REQUIRE( iprint == argument::extract< 
            LEAPR::Card3::Iprint >( iss ).value );
        }
      } // THEN
    } // WHEN
    WHEN( "no iprint value is given" ){
      iRecordStream<char> iss( std::istringstream( " / " ) );
      THEN( "default value is used" ){
        REQUIRE( 1 == argument::extract<
          LEAPR::Card3::Iprint >( iss ).value );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid iprint values" ){
    std::vector<int> invalidValues{-1, 3};
    THEN( "an exception is thrown" ){
      for( auto& iprint : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( iprint ) ) );
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card3::Iprint >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
