#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card4, Ip1opt",
          "[WIMSR] [Card4] [Ip1opt]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {0, 1} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< WIMSR::Card4::Ip1opt >( iss ).value);
        }
      }
    }

    WHEN( "no value is given" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is returned" ){
        REQUIRE( 1 == argument::extract< WIMSR::Card4::Ip1opt >( iss ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( auto i : {-1, 2} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< WIMSR::Card4::Ip1opt >( iss ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
