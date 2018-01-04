#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card3 inputs",
          "[RESXSR], [Card3]" ){

  GIVEN( "valid inputs" ){

    std::string huse_1( "''" );
    std::string huse_2( "'123456789'" );
    std::string huse_3( "'1234567890123456'" );

    std::string ivers( " 10 /" );

    WHEN( "blank user identification" ){
      iRecordStream<char> issCard3( std::istringstream( huse_1 + ivers ) );

      RESXSR::Card3 card3( issCard3 );

      THEN( "the values can be verified" ){
        REQUIRE( "" == card3.huse.value );
        REQUIRE( 10 == card3.ivers.value );
      }
    }

    WHEN( "partially filled user identification" ){
      iRecordStream<char> issCard3( std::istringstream( huse_2 + ivers ) );

      RESXSR::Card3 card3( issCard3 );

      THEN( "the values can be verified" ){
        REQUIRE( "123456789" == card3.huse.value );
        REQUIRE( 10 == card3.ivers.value );
      }
    }

    WHEN( "completely filled user identification" ){
      iRecordStream<char> issCard3( std::istringstream( huse_3 + ivers ) );

      RESXSR::Card3 card3( issCard3 );

      THEN( "the values can be verified" ){
        REQUIRE( "1234567890123456" == card3.huse.value );
        REQUIRE( 10 == card3.ivers.value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){

    std::string huse_1( "'12345678901234567'" );
    std::string huse_2( "'123456789'" );
    std::string ivers( " 10 /" );

    WHEN( "user identification is too long" ){
      iRecordStream<char> issCard3( std::istringstream( huse_1 + ivers ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR::Card3( issCard3 ) );
      }
    }

    WHEN( "no ivers value provided" ){
      iRecordStream<char> issCard3( std::istringstream( huse_2 + " /" ) );

      THEN( "an excpetion is thrown" ){
        REQUIRE_THROWS( RESXSR::Card3( issCard3 ) );
      }
    }

    WHEN( "an extra value is provided" ){
      iRecordStream<char> issCard3( std::istringstream( huse_2 + " 10 11 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR::Card3( issCard3 ) );
      }
    }
  } // GIVEN
} // SCENARIO
