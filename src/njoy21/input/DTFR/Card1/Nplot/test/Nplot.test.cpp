#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "nplot output values",
  "[DTFR],[Card1], [Nplot]"){

  GIVEN( "valid inputs for nin, nout, and npend" ){
    Argument< DTFR::Card1::Nin   > nin; 
    Argument< DTFR::Card1::Nout  > nout; 
    Argument< DTFR::Card1::Npend > npend;
    nin.value = 21; nout.value = 22; npend.value = 23;
    
    WHEN( "the nplot value is valid" ){
      std::vector<int> validValues{-20, 20, 42, 99, -99};
      THEN( "the returned class has the correct tape value" ){
        for( int nplot : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string(nplot) ) );
          REQUIRE( nplot == argument::extract< 
	    DTFR::Card1::Nplot >( iss, nin, nout, npend ).value );
        }
      } // THEN
    } // WHEN

    WHEN( "no nplot value given " ){
      THEN( "default value is substituted in" ){
        iRecordStream<char> iss( std::istringstream( "  /" ) );
        REQUIRE( 0 == argument::extract<
          DTFR::Card1::Nplot > ( iss, nin, nout, npend ).value );
      } // THEN
    } // WHEN
  
    WHEN( "the nplot value equals an existing input" ){
      std::vector<int> invalidValues{21, 22, 23};
      THEN( "an exception is thrown" ){
        for( int nplot : invalidValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( nplot ) ) );
            REQUIRE_THROWS( argument::extract<
            DTFR::Card1::Nplot >( iss, nin, nout, npend ) );
        }
      } //THEN
    } // WHEN
    WHEN( "nplot tapes are out of range" ){
      std::vector<int> invalidValues{-19, 19, 0, 100, -100};
      THEN( "an exception is thrown" ){
        for( auto nplot : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string(nplot) ) );
          REQUIRE_THROWS( argument::extract<
            DTFR::Card1::Nplot>( iss, nin, nout, npend ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

