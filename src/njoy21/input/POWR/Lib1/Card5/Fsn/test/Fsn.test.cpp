#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib1, Card5, Fsn",
          "[POWR] [Lib1] [Card5] [Fsn]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( std::string i : { "123456", "12345678901234567",
                                 "1234567890123456789012345678901234567890" } ){
        std::string temp( " '" + i + "'/" );
        iRecordStream<char> iss{ std::istringstream{ temp } };

        THEN( "the value can be verified" ){
          auto test = argument::extract< POWR::Lib1::Card5::Fsn >( iss );
          REQUIRE( i == test.value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is verified" ){
        REQUIRE( "" == argument::extract< POWR::Lib1::Card5::Fsn >(
                                                                  iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream(
                            " '12345678901234567890123456789012345678901'/" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib1::Card5::Fsn >( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
