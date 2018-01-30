#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, Card1, Nisot",
          "[CCCCR] [Card1] [Nisot]" ){
  const int nin = 22;
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( auto i : { 0, -20, -48, -99 } ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< CCCCR::Card1::Nisot >( iss, nin
                                                                      ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is returned" ){
        REQUIRE( 0 == argument::extract< CCCCR::Card1::Nisot >( iss, nin
                                                                      ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid values are provided" ){
      for( auto i : {-100, -22, -19, -1, 1, 19, 20, 22, 38, 99, 100} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< CCCCR::Card1::Nisot >( iss, nin ));
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
