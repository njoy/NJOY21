#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib2, Card4, Mti",
          "[POWR] [Lib2] [Card4] [Mti]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {1, 10, 100, 1000, 9999} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the values can be verified" ){
          REQUIRE( i == argument::extract< POWR::Lib2::Card4::Mti >(
                                                                  iss ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default can be verified" ){
        REQUIRE( 0 == argument::extract< POWR::Lib2::Card4::Mti >( iss ).value);
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( auto i : {-1, 0, 10000} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< POWR::Lib2::Card4::Mti >( iss ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
