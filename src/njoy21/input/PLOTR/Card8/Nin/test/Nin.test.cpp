#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Nin input values", "[PLOTR], [Card8], [Nin]" ){
  int iverf = 2;
  GIVEN( "valid nin values" ){
    std::vector<int> validNin{ 20, 45, 99 };

    THEN( "the returned class has the correct value" ){
      for( auto nin : validNin ){
	iRecordStream<char> issNin( std::istringstream( std::to_string(nin) ) );
        REQUIRE( nin == argument::extract< PLOTR::Card8::Nin >(
                                           issNin, iverf ).value );
      }
    }
  }
  GIVEN( "invalid nin values" ){
    std::vector<int> invalidNin{ -100, -19, 0, 19, 100 };
    for( auto nin : invalidNin ){
      THEN( "an exception is thrown" ){
        iRecordStream<char> issNin( std::istringstream( std::to_string(nin) ) );
        REQUIRE_THROWS( argument::extract< PLOTR::Card8::Nin >(issNin, iverf) );
      }
    }
  }
  GIVEN( "iverf == 0" ){
    iverf = 0;
    THEN( "this value doesn't matter" ){
      std::vector<int> meaninglessNin{ -101, -88, -20, -4, 0, 4, 20, 88, 101 };
      for(auto nin : meaninglessNin){
        iRecordStream<char> iss( std::istringstream( std::to_string( nin ) ) );
        REQUIRE_NOTHROW( argument::extract< PLOTR::Card8::Nin >(
                                            iss, iverf ) );
      }
    }
  }
}

