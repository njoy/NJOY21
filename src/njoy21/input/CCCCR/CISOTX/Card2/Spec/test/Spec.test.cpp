#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CISOTX, Card2, Spec",
          "[CCCCR] [CISOTX] [Card2] [Spec]" ){
  const int ngroup = 4;
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 0.1 1.0 0.5 /" ) );

      THEN( "the values can be verified" ){
        auto spec = argument::extract< CCCCR::CISOTX::Card2::Spec >(
                                                            iss, ngroup ).value;

        REQUIRE( Approx( 0.0 ) == spec.at(0) );
        REQUIRE( Approx( 0.1 ) == spec.at(1) );
        REQUIRE( Approx( 1.0 ) == spec.at(2) );
        REQUIRE( Approx( 0.5 ) == spec.at(3) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "fewer values than expected are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 0.1 1.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::CISOTX::Card2::Spec >( 
                                                                iss, ngroup ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 0.1 -1.0 0.5 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::CISOTX::Card2::Spec >( 
                                                                iss, ngroup ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
