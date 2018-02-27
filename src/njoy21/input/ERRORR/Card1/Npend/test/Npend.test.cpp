#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Card1, Npend",
          "[ERRORR] [Card1] [Npend]" ){
  const int nendf = 50;
  GIVEN( "valid inputs" ){
    for( auto i : {-99, -49, -20, 0, 20, 49, 99} ){
      std::string situ( "valid value " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i ==
                argument::extract< ERRORR::Card1::Npend >( iss, nendf ).value );
        }
      } // WHEN
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Card1::Npend >(iss, nendf) );
      }
    } // WHEN

    for( auto i : {-100, -50, -19, 19, 50, 100} ){
      std::string situ( "invalid value " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS(
                      argument::extract< ERRORR::Card1::Npend >( iss, nendf ) );
        }
      } // WHEN
    }
  } // GIVEN
} // SCENARIO
