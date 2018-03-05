#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib2, Card3, Idtemp",
          "[POWR] [Lib2] [Card3] [Idtemp]" ){
  GIVEN( "valid inputs" ){
    for( double d : {0.0, 10.0, 1000.0} ){
      std::string situ( "valid input " + std::to_string(d) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( d*dimwits::kelvin == argument::extract<
                                     POWR::Lib2::Card3::Idtemp >( iss ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 300.0*dimwits::kelvin == argument::extract<
                                    POWR::Lib2::Card3::Idtemp >( iss ) .value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( double d : {-10.0, -1.0, -0.1} ){
      std::string situ( "invalid input " + std::to_string(d) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< POWR::Lib2::Card3::Idtemp
                                                                     >( iss ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
