#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "nmat values",
          "[RESXSR],[Card2],[Nmat]" ){

  GIVEN( "valid values" ){
    for( auto nmat : { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 } ){
      std::string situ( "valid value " + std::to_string( nmat ) +
                                                              " is returned." );
      THEN( situ.c_str() ){
        iRecordStream<char> issNmat( std::istringstream(
                            std::to_string( nmat) ) );
        REQUIRE( Approx( nmat ) == argument::extract< RESXSR::Card2::Nmat >(
                                     issNmat ).value );
      }
    }
  }

  GIVEN( "invalid values" ){
    for( auto nmat : { -1, 21 } ){
      std::string situ( "exception is thrown for invalid value " +
                                                       std::to_string( nmat ) );
      THEN( situ.c_str() ){
        iRecordStream<char> issNmat( std::istringstream(
                            std::to_string( nmat ) ) );
        REQUIRE_THROWS( argument::extract< RESXSR::Card2::Nmat >(
                        issNmat ) );
      }
    }
  }
}
