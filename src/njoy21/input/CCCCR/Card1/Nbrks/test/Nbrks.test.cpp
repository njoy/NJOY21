#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, Card1, Nbrks",
          "[CCCCR] [Card1] [Nbrks]" ){
  const int nisot = -22;
  const int nin = 23;
  GIVEN( "valid inputs" ){
    for( auto i : {99, 87, 20, 0, -20, -55, -99} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< CCCCR::Card1::Nbrks >(
                                                      iss, nisot, nin ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 0 == argument::extract< CCCCR::Card1::Nbrks >(
                                                      iss, nisot, nin ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( auto i : {-100, -23, -22, -19, -1, 1, 19, 22, 23, 100} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< CCCCR::Card1::Nbrks >( iss, nisot,
                                                                        nin ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
