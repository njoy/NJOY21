#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Card1, Nin",
          "[ERRORR] [Card1] [Nin]" ){
  const int nendf = 50;
  const int npend = 49;
  const int ngout = 48;
  const int nout = 47;
  GIVEN( "valid inputs" ){
    for( auto i : {-99, -51, -20, 0, 20, 46, 99} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< ERRORR::Card1::Nin >(
                                       iss, nendf, npend, ngout, nout ).value );
        }
      } // WHEN
    }

    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 0 == argument::extract< ERRORR::Card1::Nin >(
                                       iss, nendf, npend, ngout, nout ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){

    for( auto i : { -100, -50, -49, -48, -47, -19, 19, 47, 48, 49, 50, 100 } ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Card1::Nin >(
                                             iss, nendf, npend, ngout, nout ) );
        }
      } // WHEN
    }
  } // GIVEN
} // SCENARIO
