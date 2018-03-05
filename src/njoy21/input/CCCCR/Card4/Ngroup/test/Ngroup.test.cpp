#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, Card4, Ngroup",
          "[CCCCR] [Card4] [Ngroup]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {1, 10, 100, 1000} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< CCCCR::Card4::Ngroup >( iss ).value);
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::Card4::Ngroup >( iss ) );
      }
    } // WHEN

    for( auto i : {-10, -1, 0} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< CCCCR::Card4::Ngroup >( iss ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
