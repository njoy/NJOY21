#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CBRKXS, Card2, Atem",
          "[CCCCR] [CBRKXS] [Card2] [Atem]" ){
  const int num_vals = 4;
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 0.2 0.3 0.4 /" ) );

      THEN( "the values can be verified" ){
        auto atem = argument::extract< CCCCR::CBRKXS::Card2::Atem >(
                                                          iss, num_vals ).value;

        REQUIRE( 4 == atem.size() );
        REQUIRE( 0.1*dimwits::kelvin == atem.at( 0 ) );
        REQUIRE( 0.2*dimwits::kelvin == atem.at( 1 ) );
        REQUIRE( 0.3*dimwits::kelvin == atem.at( 2 ) );
        REQUIRE( 0.4*dimwits::kelvin == atem.at( 3 ) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "fewer values than expected are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 0.2 0.3 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::CBRKXS::Card2::Atem >(
                                                              iss, num_vals ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 0.2 0.3 -0.4 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::CBRKXS::Card2::Atem >(
                                                              iss, num_vals ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
