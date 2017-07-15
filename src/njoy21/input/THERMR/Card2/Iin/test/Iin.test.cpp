#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "THERMR iin values",
  "[THERMR],[Card2], [Iin]"){
  GIVEN( "a nonzero nendf value" ){
    Argument< THERMR::Card1::Nendf > nendf; nendf.value = 20;
    WHEN( "iin input values are valid" ){
      std::vector<int> validValues{0, 1, 2};
      THEN( "the returned class has the correct value" ){
        for( int iin : validValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( iin ) ) );
          REQUIRE( iin == argument::extract< 
            THERMR::Card2::Iin >( iss, nendf ).value );
        }
      } // THEN
    } // WHEN

    WHEN( "iin values are invalid" ){
      std::vector<int> invalidValues{-1, 3};
      THEN( "an exception is thrown" ){
        for( int iin : invalidValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( iin ) ) );
          REQUIRE_THROWS( argument::extract< 
            THERMR::Card2::Iin >( iss, nendf ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "a nendf input value of zero" ){
    Argument< THERMR::Card1::Nendf > nendf; nendf.value = 0;
    WHEN( "iin input value is valid" ){
      iRecordStream<char> iss(
        std::istringstream( "1" ) );
      THEN( "the returned class has the correct value" ){
        REQUIRE( 1 == argument::extract< 
          THERMR::Card2::Iin >( iss, nendf ).value );
      } // THEN
    } // WHEN
    WHEN( "iin values are invalid" ){
      std::vector<int> invalidValues{-1, 0, 2, 3};
      THEN( "an exception is thrown" ){
        for( int iin : invalidValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( iin ) ) );
          REQUIRE_THROWS( argument::extract< 
            THERMR::Card2::Iin >( iss, nendf ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
