#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CISOTX, Card4, Amass",
          "[CCCCR] [CISOTX] [Card4] [Amass]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( double d : {0.1, 1.0, 10.0, 100.0} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( d * dimwits::gram ==
                argument::extract< CCCCR::CISOTX::Card4::Amass >( iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::CISOTX::Card4::Amass >(iss) );
      }
    } // WHEN

    WHEN( "invalid values are provided" ){
      for( double d : {-10.0, -1.0, -0.1, 0.0} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS(argument::extract< CCCCR::CISOTX::Card4::Amass >(iss));
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
