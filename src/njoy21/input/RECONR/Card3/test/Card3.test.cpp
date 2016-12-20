#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying RECONR Card3 input", "[RECONR], [Card3]" ){
  GIVEN( "valid Material" ){
    int material{9228};

    WHEN( "both ncards and ngrid are given" ){
      THEN( "the Card1 values can be tested" ){
        iRecordStream<char> iss( std::istringstream( std::to_string(material) + " 1 2 " ) );
        RECONR::Card3 card3(iss);
        REQUIRE( 9228 == card3.mat.value );
        REQUIRE( 1 == card3.ncards.value );
        REQUIRE( not card3.ncards.defaulted );
        REQUIRE( 2 == card3.ngrid.value );
	REQUIRE( not card3.ngrid.defaulted );
      }
      THEN( "an exception is thrown when ncards is invalid" ){
        iRecordStream<char> iss( std::istringstream( std::to_string(material) + " -1 2 " ) );
        REQUIRE_THROWS( RECONR::Card3 card3(iss) );
      }
      THEN( "an exception is thrown when ngrid is invalid" ){
        iRecordStream<char> iss( std::istringstream( std::to_string(material) + " 1 -2 " ) );
        REQUIRE_THROWS( RECONR::Card3 card3(iss) );
      }
    } // WHEN

    WHEN( "ncards is given but ngrid is absent"){
      iRecordStream<char> iss( std::istringstream( std::to_string(material) + " 1 /" ) );
      RECONR::Card3 card3(iss);

      REQUIRE( 9228 == card3.mat.value );
      REQUIRE( 1 == card3.ncards.value );
      REQUIRE( not card3.ncards.defaulted );
      REQUIRE( 0 == card3.ngrid.value );
      REQUIRE( card3.ngrid.defaulted );
    } // WHEN

    WHEN( "both ncards and grid are absent" ){
      iRecordStream<char> iss( std::istringstream( std::to_string(material) + '/' ) );
      RECONR::Card3 card3(iss);

      REQUIRE( 9228 == card3.mat.value );
      REQUIRE( 0 == card3.ncards.value );
      REQUIRE( card3.ncards.defaulted );
      REQUIRE( 0 == card3.ngrid.value );
      REQUIRE( card3.ngrid.defaulted );
    }
  } // GIVEN

  GIVEN( "invalid Material" ){
    int material{-1};
    
    THEN( "an exception is thrown when reading RECONR Card3 input" ){
      iRecordStream<char> iss( std::istringstream( std::to_string(material) ) );
      REQUIRE_THROWS( RECONR::Card3 card3(iss) );
    }
  } // GIVEN
} // SCENARIO
