#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "npend output values",
         "[ACER],[Card1], [Npend]"){
  GIVEN( "valid npend tape values" ){
    std::vector<int> validValues{-20, 20, 42, 99, -99};
    WHEN( "the nendf value is valid" ){
      THEN( "the returned class has the correct tape value" ){
        for( auto npend : validValues ){
          Argument< ACER::Card1::Nendf > nendf; 
          nendf.value = 22*(npend/std::abs(npend));
          iRecordStream<char> issNpend(
              std::istringstream( std::to_string(npend) ) );
          REQUIRE(npend == argument::extract< 
                           ACER::Card1::Npend >(issNpend, nendf).value );
        }
      }
    }
    WHEN( "the nendf value is the same as the npend value" ){
      THEN( "an exception is thrown" ){
        Argument< ACER::Card1::Nendf > nendf;
        nendf.value = 22;
        iRecordStream<char> issNpend(
            std::istringstream( "22" ) );
        REQUIRE_THROWS(argument::extract< 
                       ACER::Card1::Npend >(issNpend, nendf));
      }
    }
  } // GIVEN

  GIVEN( "invalid npend tape values" ){
    Argument< ACER::Card1::Nendf > nendf;
    nendf.value = 22;
    std::vector<int> invalidValues{-19, 19, 0, 100, -100};
    for( auto npend : invalidValues ){
      iRecordStream<char> issNpend(
          std::istringstream( std::to_string(npend) ) );
      REQUIRE_THROWS(argument::extract<ACER::Card1::Npend>(
              issNpend, nendf));
    }
  } // GIVEN
} // SCENARIO

