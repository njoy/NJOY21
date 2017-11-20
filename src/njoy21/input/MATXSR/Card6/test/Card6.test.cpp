#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card6",
          "[MATXSR], [Card6]" ){
  GIVEN( "valid values" ){
    WHEN( "valid values are provided" ){
      for( auto i : { 1, 9, 100 } ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        MATXSR::Card6 card6( iss );
        THEN( "the value is verified" ){
          REQUIRE( i == card6.ngrp.value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card6( iss ) );
      }
    }

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 9 10 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card6( iss ) );
      }
    }

    WHEN( "invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " -1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card6( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
