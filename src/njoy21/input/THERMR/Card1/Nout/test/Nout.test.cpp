#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "nout output values",
  "[THERMR],[Card1], [Nout]"){
  GIVEN( "a valid nendf tape value" ){
    Argument< THERMR::Card1::Nendf > nendf; nendf.value = 21;
    Argument< THERMR::Card1::Nin   > nin;   nin.value = 22;
    
    WHEN( "nout input is within range and not equal to nendf or nin" ){
      std::vector<int> validValues{-20, 20, 42, 99, -99};
      THEN( "the returned class has the correct tape value" ){
        for( auto nout : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( nout ) ) );
          REQUIRE(nout == argument::extract< 
            THERMR::Card1::Nout >( iss, nendf, nin ).value );
        }
      } // THEN
    } // WHEN
    WHEN( "nout input is equal to previous input value" ){
      THEN( "an exception is thrown" ){
        iRecordStream<char> iss1( std::istringstream( "21" ) );
        iRecordStream<char> iss2( std::istringstream( "22" ) );
        REQUIRE_THROWS( argument::extract< 
          THERMR::Card1::Nout >( iss1, nendf, nin ) );
        REQUIRE_THROWS( argument::extract< 
          THERMR::Card1::Nout >( iss2, nendf, nin ) );
      } // THEN
    } // WHEN

    WHEN( "nout values are out of range" ){
      std::vector<int> invalidValues{-19, 19, 0, 100, -100};
      THEN( "an exception is thrown" ){
        for( auto nout : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( nout ) ) );
          REQUIRE_THROWS( argument::extract<
            THERMR::Card1::Nout>( iss, nendf, nin ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

