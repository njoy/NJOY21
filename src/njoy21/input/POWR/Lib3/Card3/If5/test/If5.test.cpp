#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card3, If5",
          "[POWR] [Lib3] [Card3] [If5]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : {0, 1, 2} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< POWR::Lib3::Card3::If5 >( iss
                                                                      ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 0 == argument::extract< POWR::Lib3::Card3::If5 >( iss ).value);
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid inputs are provided" ){
      for( auto i : {-1, 3} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< POWR::Lib3::Card3::If5 >( iss ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
