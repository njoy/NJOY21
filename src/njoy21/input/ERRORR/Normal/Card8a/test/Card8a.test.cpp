#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card8a",
          "[ERRORR] [Normal] [Card8a]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1 10 100 1000 9999 /" ) );
      const std::vector<int> inp{1, 10, 100, 1000, 9999};

      THEN( "the values can be verified" ){
        ERRORR::Normal::Card8a card8a( iss, inp.size() );

        REQUIRE( inp.size() == card8a.mts.value.size() );

        for( size_t i = 0; i < inp.size(); i++ ){
          REQUIRE( inp.at(i) == card8a.mts.value.at(i) );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card8a( iss, 0 ) );
      }
    } // WHEN

    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1 5 10 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card8a( iss, 4 ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1 2 3 4 5 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card8a( iss, 4 ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 1 3 2 4 5 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card8a( iss, 5 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
