#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "eps values",
          "[RESXSR],[Card2],[Eps]" ){

  GIVEN( "valid values" ){
    for( auto eps: {0.01,0.1,1.0,10.0,100.0} ){
      std::string situ( "valid value " + std::to_string( eps ) +
                                                              " is provided." );
      THEN( situ.c_str() ){
        iRecordStream<char> issEps( std::istringstream(
                                    std::to_string( eps ) ) );

        REQUIRE( Approx( eps ) == argument::extract< RESXSR::Card2::Eps >(
                                  issEps ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid values" ){
    for( auto eps: {-10.0, -1.0, -0.1, 0.0} ){
      std::string situ( "invalid value " + std::to_string( eps ) +
                                                              " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> issEps( std::istringstream(
                                    std::to_string( eps ) ) );
  
        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< RESXSR::Card2::Eps >( issEps ) );
        }
      }
    }

    WHEN( "no value is given" ){
      iRecordStream<char> issEps( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< RESXSR::Card2::Eps >( issEps ) );
      }
    }
  } // GIVEN
} // SCENARIO
