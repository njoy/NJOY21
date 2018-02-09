#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CISOTX, Card4, Sigpot",
          "[CCCCR] [CISOTX] [Card4] [Sigpot]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( double d : {0.0, 0.1, 1.0, 10.0} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "the value is verified" ){
          REQUIRE( Approx( d ) == argument::extract<
                                  CCCCR::CISOTX::Card4::Sigpot >( iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::CISOTX::Card4::Sigpot >(iss));
      }
    } // WHEN

    WHEN( "invalid values are povided" ){
      for( double d : {-10.0, -1.0, -0.1} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract<CCCCR::CISOTX::Card4::Sigpot>(iss));
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
