#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, DummyMF33",
          "[ERRORR] [DummyMF33]" ){
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
        ERRORR::DummyMF33 dummyMF33( iss );

        REQUIRE( 20 == dummyMF33.card2.nin.value );
        REQUIRE( 21 == dummyMF33.card2.nout.value );

        REQUIRE( 4 == dummyMF33.card3List.size() );

        REQUIRE( 1 == dummyMF33.card3List.at(0).mt.value );
        REQUIRE( 2 == dummyMF33.card3List.at(1).mt.value );
        REQUIRE( 102 == dummyMF33.card3List.at(2).mt.value );
        REQUIRE( 600 == dummyMF33.card3List.at(3).mt.value );
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
        REQUIRE_THROWS( ERRORR::DummyMF33( iss ) );
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
        REQUIRE_THROWS( ERRORR::DummyMF33( iss ) );
      }
    } // WHEN

    WHEN( "no materials are provided" ){
      std::string inp(
 " 20 21 /\n"
 " 0 /" );
      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::DummyMF33( iss ) );
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
        REQUIRE_THROWS( ERRORR::DummyMF33( iss ) );
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
        REQUIRE_THROWS( ERRORR::DummyMF33( iss ) );
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
        REQUIRE_THROWS( ERRORR::DummyMF33( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
