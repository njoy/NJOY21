#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  GIVEN( "valid thnmax parameters" ){
    THEN( "the returned class has the correct value" ){
      for( auto thnmax : {-0.01, 0.0, 0.01, 1.0, 1E6 } ){
        iRecordStream<char> iss( 
            std::istringstream( std::to_string( thnmax ) ) );

        REQUIRE( thnmax*dimwits::electronVolt == 
                 argument::extract< BROADR::Card3::Thnmax >( iss).value );
      }
    }
  }
  GIVEN( "no thnmax value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( 0.0*dimwits::electronVolt == 
                argument::extract< BROADR::Card3::Thnmax >( iss ).value );
    }
  }
  GIVEN( "invalid thnmax parameters" ){
    THEN( "an exception is thrown" ){
      std::vector< double > invalid = {-21e+6, +21e+6};
      for ( auto value : invalid ){
        iRecordStream<char> iss( std::istringstream( std::to_string( value ) ) );
        REQUIRE_THROWS( argument::extract< BROADR::Card3::Thnmax>( iss ) );
      }
    }
  }
}
