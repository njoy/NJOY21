#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card5, Ip1opt",
          "[POWR] [Lib3] [Card5] [Ip1opt]" ){
  GIVEN( "valid input" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : {0, 1} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< POWR::Lib3::Card5::Ip1opt >(
                                                                  iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib3::Card5::Ip1opt >( iss ) );
      }
    } // WHEN

    WHEN( "invalid inputs are provided" ){
      for( auto i : {-1, 2} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< POWR::Lib3::Card5::Ip1opt >(iss));
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
