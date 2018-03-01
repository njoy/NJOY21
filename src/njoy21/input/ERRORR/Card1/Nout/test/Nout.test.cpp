#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Card1, Nout",
          "[ERRORR] [Card1] [Nout]" ){
  const int nendf = 50;
  const int npend = 49;
  const int ngout = 48;
  GIVEN( "valid inputs" ){
    for( auto i : {-99, -51, -20, 0, 20, 22, 99} ){
      std::string situ( "valid value " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< ERRORR::Card1::Nout >(
                                             iss, nendf, npend, ngout ).value );
        }
      } // WHEN
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 0 == argument::extract< ERRORR::Card1::Nout >(
                                             iss, nendf, npend, ngout ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( auto i : {-100, -50, -49, -48, -19, 19, 48, 49, 50, 100} ){
      std::string situ( "invalid value " + std::to_string(i) + "is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Card1::Nout >(
                                                   iss, nendf, npend, ngout ) );
        }
      } // WHEN
    }
  } // GIVEN
} // SCENARIO
