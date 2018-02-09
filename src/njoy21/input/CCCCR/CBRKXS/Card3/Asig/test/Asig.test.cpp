#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CBRKXS, Card3, Asig",
          "[CCCCR] [CBRKXS] [Card3] [Asig]" ){
  const int num_vals = 4;
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 0.1 0.2 0.3 /" ) );

      THEN( "the values can be verified" ){
        auto asig = argument::extract< CCCCR::CBRKXS::Card3::Asig >(
                                                          iss, num_vals ).value;

        REQUIRE( 4 == asig.size() );
        REQUIRE( Approx( 0.0 ) == asig.at( 0 ) );
        REQUIRE( Approx( 0.1 ) == asig.at( 1 ) );
        REQUIRE( Approx( 0.2 ) == asig.at( 2 ) );
        REQUIRE( Approx( 0.3 ) == asig.at( 3 ) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "fewer values than expected are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 0.1 0.2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::CBRKXS::Card3::Asig >(
                                                              iss, num_vals ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 0.1 0.2 -0.3 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::CBRKXS::Card3::Asig >(
                                                              iss, num_vals ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
