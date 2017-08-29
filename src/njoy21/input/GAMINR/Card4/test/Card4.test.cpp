#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying GAMINR Card4 input", "[GAMINR], [Card4]" ){

  GIVEN( "valid Card4 ngg input" ){
    iRecordStream<char> issCard4( std::istringstream( "24 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 / " ) );
    GAMINR::Card4 card4( issCard4 );

    THEN( "the ngg parameter can be verified" ){
      REQUIRE( 24 == card4.ngg.value );
    }
  }
  GIVEN( "invalid ngg" ){
    iRecordStream<char> issCard4( std::istringstream( "-24 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 / " ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GAMINR::Card4( issCard4 ) );
    }
  }

  GIVEN( "valid energy boundaries" ){
    iRecordStream< char> issEggs( std::istringstream( " 3 1 2 3 4" ) );

    THEN( "the sigma zero cross section values can be extracted and verified" ){
      std::vector< dimwits::Quantity< dimwits::ElectronVolt > > refEggs{
        1*dimwits::electronVolt,
        2*dimwits::electronVolt,
        3*dimwits::electronVolt,
        4*dimwits::electronVolt};

      GAMINR::Card4 card4( issEggs );
      REQUIRE( refEggs == card4.egg.value );
    }
  }
  GIVEN( "invalid egg---not enough energy boundaries" ){
    iRecordStream< char> issTemps( std::istringstream( " 3 1 2 3 " ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GAMINR::Card4( issTemps ) );
    }
  }
  GIVEN( "invalid sigz---too many sigma zero values" ){
    iRecordStream< char> issTemps( std::istringstream( " 3 1 2 3 4 5 " ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GAMINR::Card4( issTemps ) );
    }
  }
  GIVEN( "out of order values" ){
    iRecordStream< char> issTemps( std::istringstream( " 3 1 3 2 4 5 " ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GAMINR::Card4( issTemps ) );
    }
  }
} // SCENARIO

