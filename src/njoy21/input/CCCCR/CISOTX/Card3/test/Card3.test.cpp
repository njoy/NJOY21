#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CISOTX, Card3",
          "[CCCCR] [CISOTX] [Card3]" ){
  const int ichix = 3;
  const int ngroup = 4;
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream(
                       " 0.0 0.1 0.2 0.3 1.0 1.1 1.2 1.3 2.0 2.1 2.2 2.3 /" ) );

      THEN( "the values can be verified" ){
        CCCCR::CISOTX::Card3 card3( iss, ngroup, ichix );

        for( int i = 0; i < ichix; i++ ){
          for( int j = 0; j < ngroup; j++ ){
            REQUIRE( Approx( i*1.0 + j*0.1 ) == card3.spec.at(i).at(j);
          }
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream(
                   " 0.0 0.1 0.2 0.3 1.0 1.1 1.2 1.3 2.0 2.1 2.2 2.3 2.4 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CISOTX::Card3( iss, ngroup, ichix ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
