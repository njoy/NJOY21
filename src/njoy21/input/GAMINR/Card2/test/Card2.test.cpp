#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card2 inputs", "[GAMINR], [Card2]" ){
  WHEN( "all optional values are are given" ){
    iRecordStream<char> issCard2( 
        std::istringstream( "5100 4 1 4 0 /" ) );
    GAMINR::Card2 card2( issCard2 );

    THEN( "the card2 values can be verified" ){
      REQUIRE( 5100 == card2.matb.value );
      REQUIRE( 4 == card2.igg.value );
      REQUIRE( 1 == card2.iwt.value );
      REQUIRE( 4 == card2.lord.value );
      REQUIRE( 0 == card2.iprint.value );
    }
  }
  WHEN( "none of the optional values are given" ){
    iRecordStream<char> issCard2( std::istringstream( "5100 4 1 4 /" ) );
    GAMINR::Card2 card2( issCard2 );

    THEN( "the card2 values can be verified" ){
      REQUIRE( 5100 == card2.matb.value );
      REQUIRE( 4 == card2.igg.value );
      REQUIRE( 1 == card2.iwt.value );
      REQUIRE( 4 == card2.lord.value );
      REQUIRE( 1 == card2.iprint.value );
    }
  }

  GIVEN( "invalid Card2 input" ){
    WHEN( "parameters are incorrect" ){
      iRecordStream<char> issCard2( std::istringstream( " -1 4 1 4 /" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GAMINR::Card2(issCard2 ) );
      }
    }
    WHEN( "parameters are incorrect" ){
      iRecordStream<char> issCard2( std::istringstream( " 3 -1 1 4 /" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GAMINR::Card2(issCard2 ) );
      }
    }
    WHEN( "parameters are incorrect" ){
      iRecordStream<char> issCard2( std::istringstream( " 3 20 1 4 /" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GAMINR::Card2(issCard2 ) );
      }
    }
    WHEN( "parameters are incorrect" ){
      iRecordStream<char> issCard2( std::istringstream( " 3 3 4 4 /" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GAMINR::Card2(issCard2 ) );
      }
    }
    WHEN( "parameters are incorrect" ){
      iRecordStream<char> issCard2( std::istringstream( " 3 3 1 -1 /" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GAMINR::Card2(issCard2 ) );
      }
    }
    WHEN( "parameters are incorrect" ){
      iRecordStream<char> issCard2( std::istringstream( " 3 20 1 4 -1 /" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( GAMINR::Card2(issCard2 ) );
      }
    }
  }
} // SCENARIO
