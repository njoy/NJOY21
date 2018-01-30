#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CISOTX, Card3, Spec",
          "[CCCCR] [CISOTX] [Card3] [Spec]" ){
  const int ichix = 3;
  const int ngroup = 4;
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream(
                       " 0.0 0.1 0.2 0.3 1.0 1.1 1.2 1.3 2.0 2.1 2.2 2.3 /" ) );

      THEN( "the values can be verified" ){
        auto spec = argument::extract< CCCCR::CISOTX::Card3::Spec >(
                                                     iss, ngroup, ichix ).value;

        for( int i = 0; i < ichix; i++ ){
          for( int j = 0; j < ngroup; j++ ){
            REQUIRE( Approx( i*1.0 + j*0.1 ) == spec.at(i).at(j);
          }
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream(
                           " 0.0 0.1 0.2 0.3 1.0 1.1 1.2 1.3 2.0 2.1 2.2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::CISOTX::Card3::Spec >(
                                                         iss, ngroup, ichix ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream(
                      " 0.0 0.1 0.2 0.3 -1.0 1.1 1.2 1.3 2.0 2.1 2.2 2.3 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::CISOTX::Card3::Spec >(
                                                         iss, ngroup, ichix ) );
      }
    }
  } // GIVEN
} // SCENARIO
