#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card9",
          "[ERRORR] [Normal] [Card9]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 0.1 0.2 0.3 /" ) );
      std::vector<double> ref{0.0, 0.1, 0.2, 0.3};

      THEN( "the values can be verified" ){
        ERRORR::Normal::Card9 card9( iss, 4, 2 );

        REQUIRE( card9.akxy.value == ref );
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default behavior can be verified" ){
        ERRORR::Normal::Card9 card9( iss, 6, 1 );
        std::vector<double> ref(6, 0.0);
        ref.at( 1 ) = 1.0;

        REQUIRE( ref == card9.akxy.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 1.0 0.1 -1.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card9( iss, 2, 3 ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 1.0 1.1 0.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card9( iss, 1, 4 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
