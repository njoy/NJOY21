#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "efirst values",
          "[RESXSR],[Card2],[Efirst]" ){

  GIVEN( "valid values" ){
    for( auto efirst : { 0.0, 0.1, 2.0, 20.1, 4002.1 } ){
      THEN( "the correct value is returned" ){
        iRecordStream<char> issEfirst( std::istringstream(
                            std::to_string( efirst ) ) );
        REQUIRE( efirst == argument::extract< RESXSR::Card2::Efirst >(
                                     issEfirst ).value );
      }
    }
  }

  GIVEN( "invalid values" ){
    for( auto efirst : { -10.0, -2.0 } ){
      THEN( "an exception is thrown" ){
        iRecordStream<char> issEfirst( std::istringstream(
                            std::to_string( efirst ) ) );
        REQUIRE_THROWS( argument::extract< RESXSR::Card2::Efirst >(
                        issEfirst ) );
      }
    }
  }
}
