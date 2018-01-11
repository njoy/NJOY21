#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib2, Card3, Name",
          "[POWR] [Lib2] [Card3] [Name]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " *12345*/" ) );

      THEN( "the value can be verified" ){
        REQUIRE( "12345" == argument::extract< POWR::Lib2::Card3::Name >(
                                                                  iss ).value );
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( "" == argument::extract< POWR::Lib2::Card3::Name >(
                                                                  iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid input is provided" ){
      iRecordStream<char> iss( std::istringstream( " *123456789012*/" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib2::Card3::Name >( iss ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
