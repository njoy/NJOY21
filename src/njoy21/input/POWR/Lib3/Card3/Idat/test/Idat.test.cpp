#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card3, Idat", 
          "[POWR] [Lib3] [Card3] [Idat]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 20180111/" ) );

      THEN( "the value can be verified" ){
        REQUIRE( 20180111 == argument::extract< POWR::Lib3::Card3::Idat >( iss
                                                                      ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib3::Card3::Idat >( iss ) );
      }
    } // WHEN

    WHEN( "invalid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 19400000/" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib3::Card3::Idat >( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
