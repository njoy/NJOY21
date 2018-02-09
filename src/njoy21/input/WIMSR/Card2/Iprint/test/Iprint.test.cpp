#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card2, Iprint",
          "[WIMSR] [Card2] [Iprint]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : {0, 1, 2} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the values can be verified" ){
          REQUIRE( i == argument::extract< WIMSR::Card2::Iprint >( iss ).value);
        }
      }
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is returned" ){
        REQUIRE( 0 == argument::extract< WIMSR::Card2::Iprint >( iss ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid values" ){
    WHEN( "invalid values are provided" ){
      for( auto i : {-1, 3} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< WIMSR::Card2::Iprint >( iss ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
