#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card7",
          "[MATXSR], [Card7]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      std::vector< std::string > validInputs{
        " '' /",
        " '' '12345' /",
        " '' '12345' '12345678' /" };
      for( unsigned int i = 0; i < validInputs.size(); i++ ){
        iRecordStream<char> iss( std::istringstream( validInputs.at(i) ) );

        MATXSR::Card7 card7( iss, i+1 );
        THEN( "the value can be verified" ){
          REQUIRE( "" == card7.htypeList.value.at(0) );
          if( i >= 1 ) REQUIRE( "12345" == card7.htypeList.value.at(1) );
          if( i >= 2 ) REQUIRE( "12345678" == card7.htypeList.value.at(2) );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid input is provided" ){
      iRecordStream<char> iss( std::istringstream( "'123456789' /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card7( iss, 1 ) );
      }
    }

    WHEN( "too many inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( "'12345678' '9' /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card7( iss, 1 ) );
      }
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card7( iss, 1 ) );
      }
    }
  } // GIVEN
} // SCENARIO
