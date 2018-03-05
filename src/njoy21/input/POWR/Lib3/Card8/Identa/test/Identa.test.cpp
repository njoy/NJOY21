#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card8, Identa",
          "[POWR] [Lib3] [Card8] [Identa]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {-99, -1, 0, 1, 100} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< POWR::Lib3::Card8::Identa >(
                                                                  iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is given" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib3::Card8::Identa >( iss ) );
      }
    } // WHEN

    WHEN( "invalid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " -100 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib3::Card8::Identa >( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
