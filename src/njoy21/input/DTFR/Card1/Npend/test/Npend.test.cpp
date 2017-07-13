#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "npend output values",
  "[DTFR],[Card1], [Npend]"){
  GIVEN( "valid nin and nout values" ){
    Argument< DTFR::Card1::Nin > nin; nin.value   = 21;
    Argument< DTFR::Card1::Nout> nout; nout.value = 22;

    WHEN( "the npend value is valid" ){
      std::vector<int> validValues{-20, 20, 0, 42, 99, -99};
      THEN( "the returned class has the correct tape value" ){
        for( int npend : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string(npend) ) );
          REQUIRE(npend == argument::extract< 
            DTFR::Card1::Npend >( iss, nin, nout).value );
        }
      } // THEN
    } // WHEN

    WHEN( "no npend value given " ){
      THEN( "default value is used" ){
        iRecordStream<char> iss( std::istringstream( "  /" ) );
        REQUIRE( 0 == argument::extract<
          DTFR::Card1::Npend > ( iss, nin, nout ).value );
      } // THEN
    } // WHEN
  
    WHEN( "the npend value is the same as nin or nout values" ){
      THEN( "an exception is thrown" ){
        iRecordStream<char> iss1(std::istringstream( "21" ) );
        REQUIRE_THROWS( argument::extract< 
          DTFR::Card1::Npend >( iss1, nin, nout ) );
        iRecordStream<char> iss2(std::istringstream( "22" ) );
        REQUIRE_THROWS( argument::extract< 
          DTFR::Card1::Npend >( iss2, nin, nout ) );
      } // THEN
    } // WHEN

    WHEN( "npend tapes are out of range" ){
      std::vector<int> invalidValues{-19, 19, 100, -100};
      THEN( "an exception is thrown" ){
        for( int npend : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string(npend) ) );
          REQUIRE_THROWS( argument::extract<
            DTFR::Card1::Npend>( iss, nin, nout ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

