#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Xerr1 output values", "[PLOTR],[Card13], [Xerr1]"){

  GIVEN( "valid Xerr1 parameters" ){
    std::vector<double> validValues{0.0,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto xerr1 : validValues ){
        iRecordStream<char> issXerr1( 
            std::istringstream( std::to_string( xerr1 ) ) );

        REQUIRE( xerr1 == argument::extract< PLOTR::Card13::Xerr1 >( 
                          issXerr1 ).value );
      }
    }
  } // GIVEN

  GIVEN( "no parameter provided" ){
    iRecordStream<char> issXerr1( std::istringstream( " /" ) );
    THEN( "the nullopt is returned" ){
      REQUIRE( std::nullopt == argument::extract< PLOTR::Card13::Xerr1 >(
                               issXerr1 ).value );
    }
  }

  GIVEN( "invalid Xerr1 parameters" ){
    std::vector<double> invalidValues{-2.0, -1.0};

    THEN( "the returned class has the correct value" ){
      for( auto xerr1 : invalidValues ){
        iRecordStream<char> issXerr1( 
            std::istringstream( std::to_string( xerr1 ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card13::Xerr1 >( 
                          issXerr1 ).value );
      }
    }
  } // GIVEN

} // SCENARIO
