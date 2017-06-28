#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying ACER Card9 input", "[ACER], [Card9]" ){
  GIVEN( "valid nmix values" ){
    std::vector<int> validNmix{1, 2};
    THEN( "the returned class has the correct value" ){
      for( auto nmix : validNmix ){
        iRecordStream<char> issNmix( 
            std::istringstream( std::to_string(nmix) ) );
        auto nmixArg = argument::extract< ACER::Card9::Nmix >(issNmix );
        REQUIRE( nmix == nmixArg.value );
      }
    }
  }
  GIVEN( "no nmix value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( 1 == argument::extract< ACER::Card9::Nmix >( iss ).value );
    }
  }
  GIVEN( "invalid nmix values" ){
    std::vector<int> invalidNmix{-1, 0, 3};
    THEN( "an exception is thrown" ){
      for( auto& nmix : invalidNmix ){
        iRecordStream< char> issNmix( std::stringstream( std::to_string(nmix) ) );
        REQUIRE_THROWS( argument::extract< ACER::Card9::Nmix >( issNmix ) );
      }
    }
  }
}
