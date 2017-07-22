#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "nplot output values",
  "[HEATR], [Card1], [Nplot]"){
  GIVEN( "a valid nendf tape value" ){
    Argument< HEATR::Card1::Nendf > nendf; nendf.value = 21;
    Argument< HEATR::Card1::Nin   > nin;   nin.value   = 22;
    Argument< HEATR::Card1::Nout  > nout;  nout.value  = 23;
    
    WHEN( "nplot is within range and not equal to nendf, nin, or nout" ){
      std::vector<int> validValues{-20, 20, 0, 42, 99, -99};
      THEN( "the returned class has the correct tape value" ){
        for( auto nplot : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( nplot ) ) );
          REQUIRE(nplot == argument::extract< 
            HEATR::Card1::Nplot >( iss, nendf, nin, nout ).value );
        }
      } // THEN
    } // WHEN
    WHEN( "nplot input is equal to a preceding tape value" ){
      std::vector<int> invalidValues{ -21, 21, -22, 22, -23, 23 };
      THEN( "an exception is thrown" ){
         for( auto nplot : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( nplot ) ) );
          REQUIRE_THROWS( argument::extract<
            HEATR::Card1::Nplot>( iss, nendf, nin, nout ) );
        }
      } // THEN
    } // WHEN

    WHEN( "nplot values are out of range" ){
      std::vector<int> invalidValues{-19, 19, 100, -100};
      THEN( "an exception is thrown" ){
        for( auto nplot : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( nplot ) ) );
          REQUIRE_THROWS( argument::extract<
            HEATR::Card1::Nplot>( iss, nendf, nin, nout ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

