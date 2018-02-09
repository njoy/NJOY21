#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CBRKXS, Card3",
          "[CCCCR] [CBRKXS] [Card3]" ){
  const int nzi = 3;
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 0.1 0.2 /" ) );

      THEN( "the values can be verified" ){
        CCCCR::CBRKXS::Card3 card3( iss, nzi );

        auto asig = card3.asig.value;

        REQUIRE( Approx( 0.0 ) == asig.at(0) );
        REQUIRE( Approx( 0.1 ) == asig.at(1) );
        REQUIRE( Approx( 0.2 ) == asig.at(2) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CBRKXS::Card3( iss, nzi ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 0.1 0.2 0.3 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CBRKXS::Card3( iss, nzi ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
