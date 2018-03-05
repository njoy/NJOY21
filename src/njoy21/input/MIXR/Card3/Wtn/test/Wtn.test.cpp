#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MIXR, Card3, Wtn",
          "[MIXR] [Card3] [Wtn]" ){
  GIVEN( "valid inputs" ){
    for( double d : {0.1, 0.5, 1.0} ){
      std::string situ( "valid input " + std::to_string(d) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE( Approx( d ) ==
                           argument::extract< MIXR::Card3::Wtn >( iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MIXR::Card3::Wtn >( iss ) );
      }
    } // WHEN

    for( double d : { 0.0, 1.01 } ){
      std::string situ( "invalid input " + std::to_string(d) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< MIXR::Card3::Wtn >( iss ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
