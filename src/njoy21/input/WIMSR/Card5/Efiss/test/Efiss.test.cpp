#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card5, Efiss",
          "[WIMSR] [Card5] [Efiss]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( auto i : {1.0, 5.0, 10.0, 100.0, 1000.0} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( Approx( i ) == argument::extract< WIMSR::Card5::Efiss >
                                  ( iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid inputs are provided" ){
      for( auto i : {-10.0, 0.0 } ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< WIMSR::Card5::Efiss >( iss ) );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card5::Efiss >( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
