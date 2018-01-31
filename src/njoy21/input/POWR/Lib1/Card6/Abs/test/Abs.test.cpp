#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib1, Card6, Abs",
          "[POWR] [Lib1] [Card6] [Abs]" ){
  GIVEN( "valid inputs" ){
    WHEN( "a random input is provided" ){
      iRecordStream<char> iss( std::istringstream( " 1.0 2.0 3.0 /" ) );

      THEN( "the values can be verified" ){
        auto abs = argument::extract< POWR::Lib1::Card6::Abs >( iss, 3 ).value;

        REQUIRE( Approx( 1.0 ) == abs.at(0) );
        REQUIRE( Approx( 2.0 ) == abs.at(1) );
        REQUIRE( Approx( 3.0 ) == abs.at(2) );
      }
    } // WHEN

    WHEN( "no values are given" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default can be verified" ){
        auto abs = argument::extract< POWR::Lib1::Card6::Abs >( iss, 68 ).value;

        REQUIRE( abs.size() == 68 );

        for( auto i : abs ){
          REQUIRE( Approx( 0.0 ) == i );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
