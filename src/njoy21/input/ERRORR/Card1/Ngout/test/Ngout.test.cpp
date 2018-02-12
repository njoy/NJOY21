#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Card1, Ngout",
          "[ERRORR] [Card1] [Ngout]" ){
  const int nendf = 50;
  const int npend = 49;
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : {-99, -30, -20, 20, 30, 99} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< ERRORR::Card1::Ngout >(
                                                    iss, nendf, npend ).value );
        }
      }
    } // WHEN

    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 0 == argument::extract< ERRORR::Card1::Ngout >(
                                                    iss, nendf, npend ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid values are provided" ){
      for( auto i : {-100, -50, -49, -19, 0, 19, 49, 50, 100} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Card1::Ngout >(
                                                          iss, nendf, npend ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
