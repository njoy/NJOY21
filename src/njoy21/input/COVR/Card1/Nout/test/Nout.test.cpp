#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "nout output values",
  "[COVR], [Card1], [Nout]"){
  GIVEN( "a nin tape value" ){
    Argument< COVR::Card1::Nin > nin; nin.value = 22;
    WHEN( "nout input is within range and not equal to nin" ){
      std::vector<int> validValues{-20, 20, 0, 42, 99, -99};
      THEN( "the returned class has the correct tape value" ){
        for( auto& nout : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( nout ) ) );
          REQUIRE(nout == argument::extract< 
            COVR::Card1::Nout >( iss, nin ).value );
        }
      } // THEN
    } // WHEN
    WHEN( "nout input is equal to nin value" ){
      THEN( "an exception is thrown" ){
        iRecordStream<char> iss(
          std::istringstream( "22" ) );
        REQUIRE_THROWS( argument::extract< 
          COVR::Card1::Nout >( iss, nin ) );
      } // THEN
    } // WHEN

    WHEN( "nout values are out of range" ){
      std::vector<int> invalidValues{-19, 19, 100, -100};
      THEN( "an exception is thrown" ){
        for( auto& nout : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( nout ) ) );
          REQUIRE_THROWS( argument::extract<
            COVR::Card1::Nout>( iss, nin ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

