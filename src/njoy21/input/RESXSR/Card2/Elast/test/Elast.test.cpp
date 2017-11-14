#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "elast values",
          "[RESXSR],[Card2],[Elast]" ){
  const double ef = 2.0;

  GIVEN( "valid values" ){
    for( auto elast : { 2.2, 9.1, 1000.0, 103303.1 } ){
      THEN( "the correct value is returned" ){
        iRecordStream<char> issElast( std::istringstream(
                                      std::to_string( elast ) ) );
        REQUIRE( elast == argument::extract< RESXSR::Card2::Elast >(
                                    issElast, ef ).value );
      }
    }
  }

  GIVEN( "invalid values" ){
    for( auto elast : { -20.0, -1.0, 0.0, 1.9 } ){
      THEN( "an exception is thrown" ){
        iRecordStream<char> issElast( std::istringstream(
                                      std::to_string( elast ) ) );
        REQUIRE_THROWS( argument::extract< RESXSR::Card2::Elast >(
                        issElast, ef ) );
      }
    }
  }
}
