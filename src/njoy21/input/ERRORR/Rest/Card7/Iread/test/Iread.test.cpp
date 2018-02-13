#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Rest, Card7, Iread",
          "[ERRORR] [Rest] [Card7] [Iread]" ){
  GIVEN( "valid inputs" ){
    const int ngout = 35;
    WHEN( "valid inputs are provided" ){
      for( auto i : {0, 1, 2} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< ERRORR::Rest::Card7::Iread >(
                                                           iss, ngout ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 0 == argument::extract< ERRORR::Rest::Card7::Iread >(
                                                           iss, ngout ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "iread = 2, ngout can't be zero" ){
      const int ngout = 0;
      iRecordStream<char> iss( std::istringstream( " 2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Rest::Card7::Iread >(
                                                                 iss, ngout ) );
      }
    } // WHEN

    WHEN( "invalid values are provided" ){
      const int ngout = 35;
      for( auto i : {-1, 3} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Rest::Card7::Iread >(
                                                                 iss, ngout ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
