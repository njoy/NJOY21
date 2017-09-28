#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Temper input values", "[PLOTR], [Card8], [Temper]" ){
  Argument< PLOTR::Card8::Iverf > iverf; iverf.value = 2;
  GIVEN( "valid temper values" ){
    std::vector<double> validTemper{ 0.0, 293.6, 500.1 };

    THEN( "the returned class has the correct value" ){
      for( auto temper : validTemper ){
	iRecordStream<char> issTemper( std::istringstream(
                             std::to_string(temper) ) );
        auto temperArg = argument::extract< PLOTR::Card8::Temper >( 
                                            issTemper, iverf.value );
        REQUIRE( temper * dimwits::kelvin == temperArg.value );
      }
    }
  }//GIVEN
  GIVEN( "no temper value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( 0*dimwits::kelvin == 
               argument::extract< PLOTR::Card8::Temper >( 
                                                iss, iverf.value ).value );
    }
  }//GIVEN
  GIVEN( "invalid temper values" ){
    double temper(-0.01);
    THEN( "an exception is thrown" ){
      iRecordStream<char> issTemper( std::istringstream(
                           std::to_string(temper) ) );
      REQUIRE_THROWS( argument::extract< PLOTR::Card8::Temper >(
                                                     issTemper, iverf.value ) );
    }
  }//GIVEN
  GIVEN( "iverf == 0" ){
    iverf.value = 0;
    std::vector<double> meaninglessTemper{ -10.0, 0.0, 10.0, 40000.0 };
    THEN( "temper value doesn't matter" ){
      for( auto tmp : meaninglessTemper ){
        iRecordStream<char> issTemper( std::istringstream(
                             std::to_string(tmp) ) );
        REQUIRE_NOTHROW( argument::extract< PLOTR::Card8::Temper >(
                                                  issTemper, iverf.value ) );
      }
    }
  }//GIVEN
}

