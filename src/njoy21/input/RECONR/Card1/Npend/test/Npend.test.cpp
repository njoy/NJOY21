#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "npend output values",
         "[Card1], [Npend]"){
  GIVEN( "valid npend tape values" ){
    std::vector<int> validValues{-20, 20, 42, 99, -99};

    WHEN( "the nendf value is valid" ){
      THEN( "the returned class has the correct tape value" ){
        for( auto npend : validValues ){
          Argument< RECONR::Card1::Nendf > nendf; 
          nendf.value = 22 * ( npend / std::abs(npend) );
          iRecordStream<char> iss( std::istringstream( std::to_string( npend ) ) );
          REQUIRE(npend ==
		  argument::extract< RECONR::Card1::Npend >( iss, nendf ).value );
        }
      }
    }
    WHEN( "the nendf value is the same as the npend value" ){
      THEN( "an exception is thrown" ){
        Argument< RECONR::Card1::Nendf > nendf;
        nendf.value = 22;
        iRecordStream<char> iss( std::istringstream("22") );
        REQUIRE_THROWS( argument::extract< RECONR::Card1::Npend >(iss, nendf ) );
      }
    }
  } // GIVEN

  GIVEN( "invalid npend tape values" ){
    Argument< RECONR::Card1::Nendf > nendf;
    nendf.value = 22;
    std::vector<int> invalidValues{-19, 19, 100, -100};
    for( auto npend : invalidValues ){
      iRecordStream< char > iss( std::istringstream( std::to_string( npend ) ) );
      REQUIRE_THROWS( argument::extract< RECONR::Card1::Npend >( iss, nendf ) );
    }
  } // GIVEN
} // SCENARIO
