#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Dummy",
          "[ERRORR] [Dummy]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      std::string inp(
 " 20 21 /\n"
 " 1 /\n"
 " 2 /\n"
 " 102 /\n"
 " 600 /\n"
 " 0 /" );
      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        ERRORR::Dummy dummy( iss );

        REQUIRE( 20 == dummy.card2.nin.value );
        REQUIRE( 21 == dummy.card2.nout.value );

        REQUIRE( 4 == dummy.card3List.size() );

        REQUIRE( 1 == dummy.card3List.at(0).mt.value );
        REQUIRE( 2 == dummy.card3List.at(1).mt.value );
        REQUIRE( 102 == dummy.card3List.at(2).mt.value );
        REQUIRE( 600 == dummy.card3List.at(3).mt.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no termination card is provided" ){
      std::string inp(
 " 20 21 /\n"
 " 1 /\n"
 " 2 /\n"
 " 102 /\n"
 " 600 /" );
      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Dummy( iss ) );
      }
    } // WHEN

    WHEN( "an invalid material is provided" ){
      std::string inp(
 " 20 21 /\n"
 " 1 /\n"
 " 2 /\n"
 " -102 /\n"
 " 0 /" );
      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Dummy( iss ) );
      }
    } // WHEN

    WHEN( "no materials are provided" ){
      std::string inp(
 " 20 21 /\n"
 " 0 /" );
      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Dummy( iss ) );
      }
    } // WHEN

    WHEN( "more than 5 materials are provided" ){
      std::string inp(
 " 20 21 /\n"
 " 1 /\n"
 " 2 /\n"
 " 102 /\n"
 " 104 /\n"
 " 600 /\n"
 " 700 /\n"
 " 0 /" );
      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Dummy( iss ) );
      }
    } // WHEN

    WHEN( "a material is provided more than once" ){
      std::string inp(
 " 20 21 /\n"
 " 1 /\n"
 " 2 /\n"
 " 102 /\n"
 " 102 /\n"
 " 0 /" );
      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Dummy( iss ) );
      }
    } // WHEN

    WHEN( "materials aren't provided in ascending order" ){
      std::string inp(
 " 20 21 /\n"
 " 1 /\n"
 " 2 /\n"
 " 600 /\n"
 " 102 /\n"
 " 0 /" );
      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Dummy( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
