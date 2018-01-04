#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card6",
          "[MATXSR], [Card6]" ){
  GIVEN( "valid values" ){
    WHEN( "valid values are provided" ){
      std::vector< std::string > validInputs{
        " 1 /",
        " 1 9 /",
        " 1 9 100 /" };
      for( unsigned int i = 0; i < validInputs.size(); i++ ){
        iRecordStream<char> iss( std::istringstream( validInputs.at(i) ) );

        MATXSR::Card6 card6( iss, i+1 );
        THEN( "the values can be verified" ){
          REQUIRE( 1 == card6.ngrpList.value.at(0) );
          if( i >= 1 ) REQUIRE( 9 == card6.ngrpList.value.at(1) );
          if( i >= 2 ) REQUIRE( 100 == card6.ngrpList.value.at(2) );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card6( iss, 1 ) );
      }
    }

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 9 10 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card6( iss, 1 ) );
      }
    }

    WHEN( "invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " -1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card6( iss, 1 ) );
      }
    }
  } // GIVEN
} // SCENARIO
