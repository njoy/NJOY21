#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Card4 mat1 input values",
  "[COVR], [Card4], [Mat1]" ){
  GIVEN( "mat1 tape values are valid" ){
    std::vector<int> validValues{1, 125, 9998, 9999};
    WHEN( "a mat1 value is provided" ){
      THEN( "the returned class has the correct tape value" ){
        for( auto mat1 : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( mat1 ) ) );
          REQUIRE( mat1 == argument::extract< 
            COVR::Card4::Mat1 >( iss ).value );
        }
      } // THEN
    } // WHEN
    WHEN( "no mat1 value is provided" ){
      THEN( "the default value is substituted" ){    
        iRecordStream<char> iss( std::istringstream( " / " ) );
        REQUIRE( 0 == argument::extract< 
          COVR::Card4::Mat1 >( iss ).value );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "mat1 tape values are invalid" ){
    std::vector<int> invalidValues{-20, -1, 0, 10000, 10001};
    THEN( "an exception is thrown" ){
      for( auto mat1 : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( mat1 ) ) );
        REQUIRE_THROWS( argument::extract< 
          COVR::Card4::Mat1 >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
