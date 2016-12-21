#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying PURR Card2 input",
          "[PURR], [Card2]" ){
  GIVEN( "valid Material" ){
    int material{9228};
    
    WHEN( "all optional values are given" ){
      THEN( "the Card2 values can be verified" ){
        long ln(0);
        iRecordStream< char > issCard2(std::istringstream(  
            std::to_string(material) + " 3 2 16 85 0 5 /\n" ));

        PURR::Card2 card2( issCard2 );

        REQUIRE( material == card2.matd.value );
        REQUIRE( 3 == card2.ntemp.value );
        REQUIRE( 2 == card2.nsigz.value );
        REQUIRE( 16 == card2.nbin.value );
        REQUIRE( 85 == card2.nladr.value );
        REQUIRE( 0 == card2.iprint.value );
        REQUIRE( 5 == card2.nunx.value );
      }
    }
    WHEN( "none of the optional values are given" ){
      THEN( "the Card2 values can be verified" ){
        long ln(0);
        iRecordStream< char > issCard2(
            std::istringstream(  std::to_string(material) + " /\n"  ));

        PURR::Card2 card2( issCard2 );

        REQUIRE( material == card2.matd.value );
        REQUIRE( 1 == card2.ntemp.value );
        REQUIRE( 1 == card2.nsigz.value );
        REQUIRE( 20 == card2.nbin.value );
        REQUIRE( 64 == card2.nladr.value );
        REQUIRE( 1 == card2.iprint.value );
        REQUIRE( 0 == card2.nunx.value );
      }
    }

    material = 0;
    WHEN( "none of the optional values are given" ){
      THEN( "the Card2 values can be verified" ){
        long ln(0);
        iRecordStream< char > issCard2(
            std::istringstream(  std::to_string(material) + " /\n"  ));

        PURR::Card2 card2( issCard2 );

        REQUIRE( material == card2.matd.value );
      }
    }
  } // GIVEN

  GIVEN( "invalid Material" ){
    int material{-1};

    THEN( "an exception is thrown when reading PURR Card2 input" ){
      iRecordStream< char > issCard2(
          std::istringstream(  std::to_string(material)  ));
      long ln{1};
      REQUIRE_THROWS( PURR::Card2 card2(issCard2 ) );
    }
  }
} // SCENARIO
