#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib1, Card3, Izref",
          "[POWR] [Lib1] [Card3] [Izref]" ){
  GIVEN( "valid inputs" ){
    for( int i : {0, 1, 10, 100, 1000} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the values can be verified" ){
          REQUIRE( i == argument::extract< POWR::Lib1::Card3::Izref >(
                                                                  iss ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is provided" ){
        REQUIRE( 1 == argument::extract< POWR::Lib1::Card3::Izref >(
                                                                  iss ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( int i : {-100, -10, -1} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< POWR::Lib1::Card3::Izref >( iss ));
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
