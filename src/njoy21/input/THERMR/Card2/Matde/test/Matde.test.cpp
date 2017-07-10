#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Card2 matde input values",
  "[THERMR], [Card2], [Matde]" ){
  GIVEN( "a nonzero nendf value" ){
    Argument< THERMR::Card1::Nendf > nendf; nendf.value = 20;
    WHEN( "matde tape values are valid" ){
      std::vector<int> validValues{1, 125, 9998, 9999};
      THEN( "the returned class has the correct tape value" ){
        for( auto matde : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( matde ) ) );
          REQUIRE( matde == argument::extract< 
            THERMR::Card2::Matde >( iss, nendf ).value );
        }
      } // THEN
    } // WHEN

    WHEN( "matde tape values are invalid" ){
      std::vector<int> invalidValues{-20, -1, 0, 10000, 10001};
      THEN( "an exception is thrown" ){
        for( auto matde : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( matde ) ) );
          REQUIRE_THROWS( argument::extract< 
            THERMR::Card2::Matde >( iss, nendf ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "a nendf value of zero" ){
    Argument< THERMR::Card1::Nendf > nendf; nendf.value = 0;
    WHEN( "matde tape value is valid" ){
      THEN( "the returned class has the correct tape value" ){
        iRecordStream<char> iss( std::istringstream( "0" ) );
	REQUIRE( 0 == argument::extract< 
          THERMR::Card2::Matde >( iss, nendf ).value );
      } // THEN
    } // WHEN
    WHEN( "matde tape value is invalid" ){
       std::vector<int> invalidValues{1, 125, 9998, 9999};
      THEN( "an exception is thrown" ){
        for( auto matde : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( matde ) ) );
          REQUIRE_THROWS( argument::extract< 
            THERMR::Card2::Matde >( iss, nendf ) );
        }
      } // THEN
    } // WHEN 
  } // GIVEN
} // SCENARIO
