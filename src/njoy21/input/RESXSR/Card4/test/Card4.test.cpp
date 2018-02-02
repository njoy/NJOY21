#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card4 inputs",
          "[RESXSR], [Card4]" ){

  GIVEN( "valid inputs" ){

    std::string holl_1( "''" );
    std::string holl_2( "'123456789012345678901234567890'" );
    std::string holl_3( "'123456789012345678901234567890123456789012345678901234567890123456789012'" );

    WHEN( "blank line of hollerith data" ){
      iRecordStream<char> issCard4( std::istringstream( holl_1 + " /" ) );

      RESXSR::Card4 card4( issCard4 );

      THEN( "the value can be verified" ){
        REQUIRE( "" == card4.holl.value );
      }
    }

    WHEN( "partially filled line of hollerith data" ){
      iRecordStream<char> issCard4( std::istringstream( holl_2 + " /" ) );

      RESXSR::Card4 card4( issCard4 );

      THEN( "the value can be verified" ){
        REQUIRE( "123456789012345678901234567890" == card4.holl.value );
      }
    }

    WHEN( "completely filled line of hollerith data" ){
      iRecordStream<char> issCard4( std::istringstream( holl_3 + " /" ) );

      RESXSR::Card4 card4( issCard4 );

      THEN( "the value can be verified" ){
        REQUIRE( "123456789012345678901234567890123456789012345678901234567890123456789012"
                 == card4.holl.value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){

    std::string holl_1( "'1234567890123456789012345678901234567890'" );
    std::string holl_2( "'1234567890123456789012345678901234567890123456789012345678901234567890123'" );

    WHEN( "the hollerith data is too long" ){
      iRecordStream<char> issCard4( std::istringstream( holl_2 + " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR::Card4( issCard4 ) );
      }
    }

    WHEN( "an extra value is provided" ){
      iRecordStream<char> issCard4( std::istringstream( holl_1 + "'123' /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR::Card4( issCard4 ) );
      }
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> issCard4( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR::Card4( issCard4 ) );
      }
    }
  } // GIVEN
} // SCENARIO
