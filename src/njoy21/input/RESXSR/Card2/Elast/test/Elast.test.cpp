#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "elast values",
          "[RESXSR],[Card2],[Elast]" ){
  const dimwits::Quantity< dimwits::ElectronVolt > ef =
        2.0*dimwits::electronVolt;

  GIVEN( "valid values" ){
    for( auto elast : { 2.2, 9.1, 1000.0, 103303.1 } ){
      std::string situ( "valid value " + std::to_string( elast ) +
                                                              " is provided." );
      THEN( situ.c_str() ){
        iRecordStream<char> issElast( std::istringstream(
                                      std::to_string( elast ) ) );
        REQUIRE( elast*dimwits::electronVolt ==
                 argument::extract< RESXSR::Card2::Elast >(
                                    issElast, ef ).value );
      }
    }
  }

  GIVEN( "invalid values" ){
    for( auto elast : { -20.0, -1.0, 0.0, 1.9, 2.0 } ){
      std::string situ( "invalid value " + std::to_string( elast ) +
                                                              " is provided." );
      THEN( situ.c_str() ){
        iRecordStream<char> issElast( std::istringstream(
                                      std::to_string( elast ) ) );
        REQUIRE_THROWS( argument::extract< RESXSR::Card2::Elast >(
                        issElast, ef ) );
      }
    }
  }
}
