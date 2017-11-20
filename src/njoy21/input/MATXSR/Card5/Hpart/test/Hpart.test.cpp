#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card5 hpart",
          "[MATXSR], [Card5], [Hpart]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( std::string i : { "", "12345", "12345678" } ){
        iRecordStream<char> iss( std::istringstream( "'" + i + "'" ) );

        THEN( "the value is verified" ){
          REQUIRE( i == argument::extract< MATXSR::Card5::Hpart >( iss ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card5::Hpart >( iss ) );
      }
    }

    WHEN( "the provided value is invalid" ){
      iRecordStream<char> iss( std::istringstream( "'123456789'" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card5::Hpart >( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
