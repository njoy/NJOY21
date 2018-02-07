#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card5, Posr",
          "[POWR] [Lib3] [Card5] [Posr]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( auto i : {0, 1, 10, 100} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< POWR::Lib3::Card5::Posr >(
                                                                  iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib3::Card5::Posr >( iss ) );
      }
    } // WHEN

    WHEN( "invalid values are provided" ){
      for( auto i : {-10, -5, -1} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< POWR::Lib3::Card5::Posr >( iss ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
