#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying ACER Card9 input", "[ACER], [Card9]" ){
  GIVEN( "valid emax values" ){
    std::vector<double> validEmax{10.1, 4, 0.01};
    THEN( "the returned class has the correct value" ){
      for( auto emax : validEmax ){
        iRecordStream<char> issEmax( 
            std::istringstream( std::to_string(emax) ) );
        auto emaxArg = argument::extract< ACER::Card9::Emax >(issEmax );
        REQUIRE( emax == emaxArg.value );
      }
    }
  }
  GIVEN( "no emax value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( ACER::Card9::Emax::defaultValue() == 
                argument::extract< ACER::Card9::Emax >( iss ).value );
    }
  }
  GIVEN( "invalid emax values" ){
    std::vector<double> invalidEmax{-1.0, 0.0};
    THEN( "an exception is thrown" ){
      for( auto& emax : invalidEmax ){
        iRecordStream< char> issEmax( std::stringstream( std::to_string(emax) ) );
        REQUIRE_THROWS( argument::extract< ACER::Card9::Emax >( issEmax ) );
      }
    }
  }
}

