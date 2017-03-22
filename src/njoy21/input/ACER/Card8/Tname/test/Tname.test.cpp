#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ACER Card8 Tname", "[Card8], [Tname]"){
  GIVEN( "valid tname values" ){
    std::vector< std::string > validValues{ "lwtr", "h-zr", "u-o2" };
    THEN( "the tname value is correctly read and returned" ){
      for( auto& tname : validValues ){
        iRecordStream<char> iss( std::istringstream( "'" + tname + "'" ) );

        REQUIRE( 
            tname == argument::extract< ACER::Card8::Tname >( iss ).value );
      }
    }
  }
  GIVEN( "invalid tname values" ){
    THEN( "an exception is thrown" ){
      std::string value( "1234567" );
      iRecordStream<char> iss( std::istringstream( "'" + value + "'" ) );
      REQUIRE_THROWS( argument::extract< ACER::Card8::Tname >( iss ) );
    }
  }
} // SCENARIO
