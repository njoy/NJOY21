#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "nout output values",
  "[DTFR],[Card1], [Nout]"){
  GIVEN( "a valid nin value" ){
    Argument< DTFR::Card1::Nin > nin; nin.value = 22;
    
    WHEN( "the nout value is valid" ){
      std::vector<int> validValues{20, 42, 99};
      THEN( "the returned class has the correct tape value" ){
        for( auto nout : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string(nout) ) );
          REQUIRE(nout == argument::extract< 
            DTFR::Card1::Nout >( iss, nin ).value );
        }
      } // THEN
    } // WHEN
    WHEN( "the nin value is the same as the nout value" ){
      THEN( "an exception is thrown" ){
        iRecordStream<char> iss(
          std::istringstream( "22" ) );
        REQUIRE_THROWS(argument::extract< DTFR::Card1::Nout >(iss, nin));
      } // THEN
    } // WHEN
    
    WHEN( "The nout values are out of range" ){
      std::vector<int> invalidValues{-19, 19, -20, -99, 100, -100};
      THEN( "an exception is thrown" ){
        for( auto nout : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string(nout) ) );
          REQUIRE_THROWS(argument::extract<DTFR::Card1::Nout>( iss, nin ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

