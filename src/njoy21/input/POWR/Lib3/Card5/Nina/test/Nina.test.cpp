#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card5, Nina",
          "[POWR] [Lib3] [Card5] [Nina]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {0, 1, 2, 3} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< POWR::Lib3::Card5::Nina >(
                                                                  iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib3::Card5::Nina >( iss ) );
      }
    } // WHEN

    for( auto i : {-1, 4} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< POWR::Lib3::Card5::Nina >( iss ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
