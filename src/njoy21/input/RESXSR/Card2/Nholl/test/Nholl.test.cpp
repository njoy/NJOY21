#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "nholl values",
          "[RESXSR],[Card2],[Nholl]" ){

  GIVEN( "valid values" ){
    for( auto nholl : { 0,1,2,3,4,5,6,7,8,9,10 } ){
      THEN( "the correct value is returned" ){
        iRecordStream<char> issNholl( std::istringstream(
                            std::to_string( nholl) ) );
        REQUIRE( Approx( nholl ) == argument::extract< RESXSR::Card2::Nholl >(
                                     issNholl ).value );
      }
    }
  }

  GIVEN( "invalid values" ){
    for( auto nholl : { -1, 11 } ){
      THEN( "an exception is thrown" ){
        iRecordStream<char> issNholl( std::istringstream(
                            std::to_string( nholl ) ) );
        REQUIRE_THROWS( argument::extract< RESXSR::Card2::Nholl >(
                        issNholl ) );
      }
    }
  }
}
