#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CBRKXS, Card1, Nti",
          "[CCCCR] [CBRKXS] [Card1] [Nti]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {-20, -10, -1, 1, 10, 20} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i ==
                  argument::extract< CCCCR::CBRKXS::Card1::Nti >( iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::CBRKXS::Card1::Nti >( iss ) );
      }
    } // WHEN

    for( auto i : {-21, 0, 21} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< CCCCR::CBRKXS::Card1::Nti >(iss) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
