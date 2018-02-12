#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Card1, Nstan",
          "[ERRORR] [Card1] [Nstan]" ){
  const int nendf = 50;
  const int npend = 49;
  const int ngout = 48;
  const int nout = 47;
  const int nin = 46;
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( auto i : {-99, -51, -20, 20, 45, 99} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< ERRORR::Card1::Nstan >(
                                  iss, nendf, npend, ngout, nout, nin ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 0 == argument::extract< ERRORR::Card1::Nstan >(
                                  iss, nendf, npend, ngout, nout, nin ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid values are provided" ){
      for( auto i :
         {-100, -50, -49, -48, -47, -46, -19, 0, 19, 46, 47, 48, 49, 50, 100} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Card1::Nstan >(
                                        iss, nendf, npend, ngout, nout, nin ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
