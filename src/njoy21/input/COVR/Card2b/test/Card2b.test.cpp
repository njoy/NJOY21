#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR card2b values",
          "[COVR], [Card2b]"){

  GIVEN( "valid input for card2b" ){
    WHEN( "all card2b inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( "4 2 /" ) );

      THEN( "the returned class has the correct tape value" ){
          COVR::Card2b card2b( iss );

          REQUIRE( card2b.matype.value == 4 );
          REQUIRE( card2b.ncase.value  == 2 );
      } // THEN
    } // WHEN

    WHEN( "optional card2b input values omitted" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "default values are substituted in" ){
        COVR::Card2b card2b( iss );

        REQUIRE( card2b.matype.value == 3 );
        REQUIRE( card2b.ncase.value  == 1 );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid input for card2b" ){
    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( "2 2" ) );

      THEN( "an exception is thrown" ){ 
        REQUIRE_THROWS( COVR::Card2b( iss ) );
      } // THEN
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 4 2 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( COVR::Card2b( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO

