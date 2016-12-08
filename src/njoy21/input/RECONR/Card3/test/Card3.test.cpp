#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying RECONR Card3 input",
         "[RECONR], [Card3]"){
  GIVEN( "valid Material" ){
    int material{9228};

    WHEN( "both ncards and ngrid are given" ){
      THEN( "the Card1 values can be tested" ){
        long ln{0};
        std::istringstream issCard3( std::to_string(material) + " 1 2 " );
        RECONR::Card3 card3(issCard3, ln);

        REQUIRE( 9228 == card3.mat.value );
        REQUIRE( 1 == card3.ncards.value );
        REQUIRE( 2 == card3.ngrid.value );
        REQUIRE( 1 == ln );
      }
      THEN( "an exception is thrown when ncards is invalid" ){
        long ln{0};
        std::istringstream issCard3( std::to_string(material) + " -1 2 " );
        REQUIRE_THROWS( RECONR::Card3 card3(issCard3, ln) );
      }
      THEN( "an exception is thrown when ngrid is invalid" ){
        long ln{0};
        std::istringstream issCard3( std::to_string(material) + " 1 -2 " );
        REQUIRE_THROWS( RECONR::Card3 card3(issCard3, ln) );
      }
    } // WHEN

    WHEN( "ncards is given but ngrid is absent"){
      long ln{0};
      std::istringstream issCard3( std::to_string(material) + " 1 " );
      RECONR::Card3 card3(issCard3, ln);

      REQUIRE( 9228 == card3.mat.value );
      REQUIRE( 1 == card3.ncards.value );
      REQUIRE( 0 == card3.ngrid.value );
      REQUIRE( 1 == ln );
    } // WHEN

    WHEN( "both ncards and grid are absent" ){
      long ln{0};
      std::istringstream issCard3( std::to_string(material) );
      RECONR::Card3 card3(issCard3, ln);

      REQUIRE( 9228 == card3.mat.value );
      REQUIRE( 0 == card3.ncards.value );
      REQUIRE( 0 == card3.ngrid.value );
      REQUIRE( 1 == ln );
    }
  } // GIVEN

  GIVEN( "invalid Material" ){
    int material{-1};
    
    THEN( "an exception is thrown when reading RECONR Card3 input" ){
      std::istringstream issCard3( std::to_string(material) );
      long ln = 1;
      REQUIRE_THROWS( RECONR::Card3(issCard3, ln ) );

    }
  } // GIVEN
} // SCENARIO
