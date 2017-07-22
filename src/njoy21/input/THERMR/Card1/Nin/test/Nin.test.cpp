#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "nin output values",
  "[THERMR],[Card1], [Nin]"){
  GIVEN( "a valid nendf tape value" ){
    Argument< THERMR::Card1::Nendf > nendf; nendf.value = 22;
    
    WHEN( "nin input is within range and not equal to nendf" ){
      std::vector<int> validValues{-20, 20, 42, 99, -99};
      THEN( "the returned class has the correct tape value" ){
        for( auto nin : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( nin ) ) );
          REQUIRE(nin == argument::extract< 
            THERMR::Card1::Nin >( iss, nendf ).value );
        }
      } // THEN
    } // WHEN
    WHEN( "nin input is equal to nendf value" ){
      THEN( "an exception is thrown" ){
        iRecordStream<char> iss(
          std::istringstream( "22" ) );
        REQUIRE_THROWS( argument::extract< 
          THERMR::Card1::Nin >( iss, nendf ) );
      } // THEN
    } // WHEN

    WHEN( "nin values are out of range" ){
      std::vector<int> invalidValues{-19, 19, 0, 100, -100};
      THEN( "an exception is thrown" ){
        for( auto nin : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( nin ) ) );
          REQUIRE_THROWS( argument::extract<
            THERMR::Card1::Nin>( iss, nendf ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

