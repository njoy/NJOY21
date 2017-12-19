#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card9",
          "[MATXSR], [Card9]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      std::vector< std::string > validInputs{
        " 0 /",
        " 0 1 /",
        " 0 1 10 /",
        " 0 1 10 100 /" };
      for( unsigned int i = 0; i < validInputs.size(); i++ ){
        iRecordStream<char> iss( std::istringstream( validInputs.at(i) ) );

        MATXSR::Card9 card9( iss, i+1 );
        THEN( "the value can be verified" ){
          REQUIRE( 0 == card9.joutpList.value.at(0) );
          if( i >= 1 ) REQUIRE( 1 == card9.joutpList.value.at(1) );
          if( i >= 2 ) REQUIRE( 10 == card9.joutpList.value.at(2) );
          if( i >= 3 ) REQUIRE( 100 == card9.joutpList.value.at(3) );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no input is given" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card9( iss, 1 ) );
      }
    }

    WHEN( "too many values are given" ){
      iRecordStream<char> iss( std::istringstream( " 1 10 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card9( iss, 1 ) );
      }
    }

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " -5 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR::Card9( iss, 1 ) );
      }
    }
  } // GIVEN
} // SCENARIO
