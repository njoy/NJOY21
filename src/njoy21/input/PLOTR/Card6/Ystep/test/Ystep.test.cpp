#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ystep output values", "[PLOTR],[Card6], [Ystep]"){

  GIVEN( "valid entries" ){
    WHEN( "valid Ystep parameters" ){
      std::vector<double> validValues{0.1,0.5,0.8,1.0,2.0,80.0};
  
      THEN( "the returned class has the correct value" ){
        for( auto ystep : validValues ){
          iRecordStream<char> issYstep( 
              std::istringstream( std::to_string( ystep ) ) );
  
          REQUIRE( ystep == *( argument::extract< PLOTR::Card6::Ystep >( 
                               issYstep ).value ) );
        }
      }
    }
  
    WHEN( "default value" ){
      Argument< PLOTR::Card6::Yl > yl;
      iRecordStream<char> issYstep( std::istringstream( " /" ) );
  
      THEN( "default value is returned" ){
        REQUIRE( std::nullopt == argument::extract< PLOTR::Card6::Ystep >(
                            issYstep ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid Ystep parameters" ){

//    WHEN( "ystep can't use the default if yl and yh didn't" ){
//      iRecordStream<char> issYstep( std::istringstream( " /" ) );
//      THEN( "an exception is thrown" ){
//        REQUIRE_THROWS( argument::extract< PLOTR::Card6::Ystep >(
//                                           issYstep, yl.value ) );
//      }
//    }

    std::vector<double> invalidValues{ -2.0, -1.1, 0.0 };
    for( auto ystep : invalidValues ){
      std::string situ( "invalid value " + std::to_string( ystep ) +
                                                              " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> issYstep( 
            std::istringstream( std::to_string( ystep ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< PLOTR::Card6::Ystep >(
                                             issYstep ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
