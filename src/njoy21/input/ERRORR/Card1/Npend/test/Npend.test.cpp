#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Card1, Npend",
          "[ERRORR] [Card1] [Npend]" ){
  const int nendf = 50;
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( auto i : {-99, -49, -20, 20, 49, 99} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i ==
                argument::extract< ERRORR::Card1::Npend >( iss, nendf ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Card1::Npend >(iss, nendf) );
      }
    } // WHEN

    WHEN( "invalid values are provided" ){
      for( auto i : {-100, -50, -19, 0, 19, 50, 100} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS(
                      argument::extract< ERRORR::Card1::Npend >( iss, nendf ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
