#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "RESXSR card5 hmat",
          "[Card5], [Hmat]" ){

  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      std::vector< std::string > hmatList{
        "",
        "12345",
        "12345678" };

      for( auto hmat : hmatList ){
        iRecordStream<char> issHmat( std::istringstream( "'" + hmat + "'" ) );

        THEN( "the value can be verified" ){
          REQUIRE( hmat ==
                   argument::extract< RESXSR::Card5::Hmat >( issHmat ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "the value provided is too long (>8 characters) " ){
      iRecordStream<char> issHmat( std::istringstream( "'123456789'" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< RESXSR::Card5::Hmat >( issHmat ) );
      }
    }

    WHEN( "there is no value provided" ){
      iRecordStream<char> issHmat( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< RESXSR::Card5::Hmat >( issHmat ) );
      }
    }
  } // GIVEN
} // SCENARIO
