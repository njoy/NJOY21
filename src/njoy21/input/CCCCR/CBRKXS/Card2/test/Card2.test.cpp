#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CBRKXS, Card2",
          "[CCCCR] [CBRKXS] [Card2]" ){
  const int nti = 3;
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 0.2 0.3 /" ) );

      THEN( "the values can be verified" ){
        CCCCR::CBRKXS::Card2 card2( iss, nti );

        auto atem = card2.atem.value;

        REQUIRE( 0.1*dimwits::kelvin == atem.at(0) );
        REQUIRE( 0.2*dimwits::kelvin == atem.at(1) );
        REQUIRE( 0.3*dimwits::kelvin == atem.at(2) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CBRKXS::Card2( iss, nti ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 0.2 0.3 0.4 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CBRKXS::Card2( iss, nti ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
