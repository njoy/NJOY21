#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR card3a values",
  "[COVR], [Card3a]"){

  GIVEN( "valid input for card3a" ){
    WHEN( "all card3a inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( "0 2 1 0 2 /" ) );

      THEN( "the returned class has the correct tape value" ){
          COVR::Card3a card3a( iss );

          REQUIRE( card3a.irelco.value == 0 );
          REQUIRE( card3a.ncase.value  == 2 );
          REQUIRE( card3a.noleg.value  == 1 );
          REQUIRE( card3a.nstart.value == 0 );
          REQUIRE( card3a.ndiv.value   == 2 );
      } // THEN
    } // WHEN

    WHEN( "optional card3a input values omitted" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "default values are substituted in" ){
        COVR::Card3a card3a( iss );

        REQUIRE( card3a.irelco.value == 1 );
        REQUIRE( card3a.ncase.value  == 1 );
        REQUIRE( card3a.noleg.value  == 0 );
        REQUIRE( card3a.nstart.value == 1 );
        REQUIRE( card3a.ndiv.value   == 1 );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid input for card3a" ){
    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( "2 2 1 0 2"  ) );

      THEN( "an exception is thrown" ){ 
        REQUIRE_THROWS( COVR::Card3a( iss ) );
      } // THEN
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( "0 2 1 0 2 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( COVR::Card3a( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO

