#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib1, Card4, Word",
          "[POWR] [Lib1] [Card4] [Word]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( std::string i : { "12345",
                             "1234567890123456" } ){
        std::string tmp( "'" + i + "'/" );
        iRecordStream<char> iss{ std::istringstream{ tmp } };

        THEN( "the value can be verified" ){
          auto test = argument::extract< POWR::Lib1::Card4::Word >( iss );
          REQUIRE( i == test.value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( "" == argument::extract< POWR::Lib1::Card4::Word >(
                                                                  iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " '12345678901234567'/ " ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib1::Card4::Word >( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
