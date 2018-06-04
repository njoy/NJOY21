#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Iopp  output values",
         "[ACER],[Card6], [Iopp]"){

  WHEN( "iopp = 1" ){

    THEN( "the returned class has he correct value" ){
          iRecordStream<char> iss( std::istringstream( "1" ) );
      REQUIRE( 1 == argument::extract< ACER::Card6::Iopp >( iss ).value );
    }
  }
  WHEN( "iopp = 0" ){

    THEN( "the returned class has he correct value" ){
          iRecordStream<char> iss( std::istringstream( "0" ) );
      REQUIRE( 0 == argument::extract< ACER::Card6::Iopp >( iss ).value );
    }
  }
  GIVEN( "no iopp values" ){

    THEN( "the default value is returned" ){
      iRecordStream<char> iss(
          std::istringstream( "/") );
      REQUIRE( ACER::Card6::Iopp::defaultValue() == 
                argument::extract< ACER::Card6::Iopp >( iss ).value );
    }
  }
  
  GIVEN( "invalid iopp values" ){
    std::vector<int> invalidValues{-1, 2};

    THEN( "an exception is thrown" ){
      for( auto& iopp : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(iopp) ) );

        REQUIRE_THROWS( argument::extract< ACER::Card6::Iopp >( iss ) );
      }
    }
  }

} // SCENARIO
