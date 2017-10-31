#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Xerr2 output values", "[PLOTR],[Card13], [Xerr2]"){

  GIVEN( "valid Xerr2 parameters" ){
    std::vector<double> validValues{0.0,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto xerr2 : validValues ){
        iRecordStream<char> issXerr2( 
            std::istringstream( std::to_string( xerr2 ) ) );

        REQUIRE( xerr2 == argument::extract< PLOTR::Card13::Xerr2 >( 
                          issXerr2 ).value );
      }
    }
  } // GIVEN

  GIVEN( "no parameter provided" ){
    iRecordStream<char> issXerr2( std::istringstream( " /" ) );
    THEN( "the default nullopt is returned" ){
      REQUIRE( std::nullopt == argument::extract< PLOTR::Card13::Xerr2 >(
                               issXerr2 ).value );
    }
  } // GIVEN

  GIVEN( "invalid Xerr2 parameters" ){
    std::vector<double> invalidValues{-2.0, -1.0};

    THEN( "the returned class has the correct value" ){
      for( auto xerr2 : invalidValues ){
        iRecordStream<char> issXerr2( 
            std::istringstream( std::to_string( xerr2 ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card13::Xerr2 >( 
                          issXerr2 ) );
      }
    }
  } // GIVEN

} // SCENARIO
