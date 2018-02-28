#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card2 huse",
          "[MATXSR], [Card2], [Huse]" ){
  GIVEN( "valid inputs" ){
    for( std::string i : { "", "12345", "1234567890123456" } ){
      std::string situ( "valid input " + i + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( "'" + i + "'/" ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< MATXSR::Card2::Huse >( iss ).value );
        }
      }
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is returned" ){
        REQUIRE( "" == argument::extract< MATXSR::Card2::Huse >( iss ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( "'12345678901234567'/" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card2::Huse >( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
