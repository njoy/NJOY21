#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  Argument< BROADR::Card2::Ntemp2 > ntemp2; 
  Argument< BROADR::Card2::Istrap > istrap; 
  istrap.value = 1;
  Argument< BROADR::Card2::Temp1 > temp1; 
  GIVEN( "ntemp2 = 1" ){
    ntemp2.value = 1;
    WHEN( "valid temperatures" ){
      temp1.value = 8.0 * dimwits::kelvin;
      THEN( "the returned class has the correct value" ){
        for( auto temp2 : { 8.1, 9.0, 10.0, 11.0 } ){
          iRecordStream<char> iss( std::istringstream( 
                  std::to_string( temp2 ) ) );

          REQUIRE( temp2*dimwits::kelvin == 
                   argument::extract< BROADR::Card4::Temp2 >(
                       iss, ntemp2, istrap, temp1 ).value.front() );
        }
      }
    }
    WHEN( "no temperatures are given" ){
      iRecordStream<char> iss( std::istringstream("   ") );
      THEN( "an exception is thrown" ){
      REQUIRE_THROWS( argument::extract< BROADR::Card4::Temp2 >
          ( iss, ntemp2, istrap, temp1 ) );
      }
    }
    WHEN( "temperature is less than temp1" ){
      temp1.value = 10.0*dimwits::kelvin;
      THEN( "an exception is thrown" ){
        iRecordStream<char> iss( 
            std::istringstream( " 9.0 " ) );
        REQUIRE_THROWS( argument::extract< BROADR::Card4::Temp2 >(
                iss, ntemp2, istrap, temp1 ) );
      }
    }
  }
  GIVEN( "ntemp2 = 2" ){
    ntemp2.value = 2;
    WHEN( "valid temperatures" ){
      iRecordStream<char> iss( std::istringstream("   100.0 200.0") );
      THEN( "the returned class has the correct value" ){
        auto temp2 = argument::extract< BROADR::Card4::Temp2 >
                     ( iss, ntemp2, istrap, temp1 );
        REQUIRE( temp2.value.front() == 100.0 * dimwits::kelvin );
        REQUIRE( temp2.value.back() == 200.0 * dimwits::kelvin );
      }
    }
    WHEN( "invalid temperatures---temperatures are not increasing" ){
      iRecordStream<char> iss( std::istringstream("   300.0 200.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< BROADR::Card4::Temp2 >
          ( iss, ntemp2, istrap, temp1 ) );
      }
    }
    WHEN( "invalid temperatures not enough temperatures" ){
      iRecordStream<char> iss( std::istringstream("   300.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< BROADR::Card4::Temp2 >
          ( iss, ntemp2, istrap, temp1 ) );
      }
    }
  }
}
