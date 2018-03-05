#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WISMR, Card3, Rdfid",
          "[WIMSR] [Card3] [Rdfid]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {1.0, 10.0, 100.0, 1000.0, 9999.0} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( Approx( i ) == 
                argument::extract< WIMSR::Card3::Rdfid >( iss, int(i) ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      const int mat = 100;
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card3::Rdfid >( iss, mat ) );
      }
    }

    for( auto i : {-1.0, 0.0, 10000.0} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        const int mat = 100;
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< WIMSR::Card3::Rdfid >( iss, mat ));
        }
      }
    }
  } // GIVEN
} // SCENARIO
