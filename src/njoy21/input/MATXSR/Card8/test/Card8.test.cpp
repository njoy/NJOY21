#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card8",
          "[MATXSR], [Card8]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      std::vector< std::string > validInputs{
        " 0 /",
        " 0 1 /",
        " 0 1 10 /",
        " 0 1 10 100 /" };
      for( unsigned int i = 0; i < validInputs.size(); i++ ){
        iRecordStream<char> iss( std::istringstream( validInputs.at( i ) ) );

        MATXSR::Card8 card8( iss, i+1 );
        THEN( "the value can be verified" ){
          REQUIRE( 0 == card8.jinpList.value.at(0) );
          if( i >= 1 ) REQUIRE( 1 == card8.jinpList.value.at(1) );
          if( i >= 2 ) REQUIRE( 10 == card8.jinpList.value.at(2) );
          if( i >= 3 ) REQUIRE( 100 == card8.jinpList.value.at(3) );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no input is given" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card8( iss, 1 ) );
      }
    }

    WHEN( "too many values are given" ){
      iRecordStream<char> iss( std::istringstream( " 1 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card8( iss, 1 ) );
      }
    }

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " -1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card8( iss, 1 ) );
      }
    }
  } // GIVEN
} // SCENARIO
