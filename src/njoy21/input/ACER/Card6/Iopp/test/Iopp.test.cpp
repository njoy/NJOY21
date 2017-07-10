#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Iopp  output values",
         "[ACER],[Card6], [Iopp]"){

  WHEN( "iopp = 1" ){
    Argument< ACER::Card1::Ngend > ngend;
    ngend.value = 22;

    THEN( "the returned class has he correct value" ){
          iRecordStream<char> iss( std::istringstream( "1" ) );
      REQUIRE( 1 == argument::extract< ACER::Card6::Iopp >(
                    iss, ngend ).value );
    }
  }
  WHEN( "iopp = 0, ngend = 22" ){
    Argument< ACER::Card1::Ngend > ngend;
    ngend.value = 22;
    int iopp = 0;

    THEN( "the returned class has he correct value" ){
          iRecordStream<char> iss( std::istringstream( 
                  std::to_string(iopp)) );
      REQUIRE( iopp == argument::extract< ACER::Card6::Iopp >(
                    iss, ngend ).value );
    }
  }
  WHEN( "iopp = 0, ngend = 0" ){
    Argument< ACER::Card1::Ngend > ngend;
    ngend.value = 0;
    int iopp = 0;

    THEN( "an exception is thrown" ){
        iRecordStream<char> iss( std::istringstream( 
                std::to_string(iopp)) );
      REQUIRE_THROWS( argument::extract< ACER::Card6::Iopp >( iss, ngend ) );
    }
  }
  GIVEN( "no iopp values" ){
    Argument< ACER::Card1::Ngend > ngend;
    ngend.value = 22;

    THEN( "the default value is returned" ){
      iRecordStream<char> iss(
          std::istringstream( "/") );
      REQUIRE( ACER::Card6::Iopp::defaultValue( ngend ) == 
                argument::extract< ACER::Card6::Iopp >( iss, ngend ).value );
    }
  }
  
  GIVEN( "invalid iopp values" ){
    std::vector<int> invalidValues{-1, 2};
    Argument< ACER::Card1::Ngend > ngend;
    ngend.value = 22;

    THEN( "an exception is thrown" ){
      for( auto& iopp : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(iopp) ) );

        REQUIRE_THROWS( argument::extract< ACER::Card6::Iopp >( iss, ngend ) );
      }
    }
  }

} // SCENARIO
