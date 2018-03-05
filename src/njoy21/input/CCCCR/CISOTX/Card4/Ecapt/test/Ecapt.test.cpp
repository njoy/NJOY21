#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CISOTX, Card4, Ecapt",
          "[CCCCR] [CISOTX] [Card4] [Ecapt]" ){
  GIVEN( "valid inputs" ){
    for( double d : {0.0, 0.1, 1.0, 10.0} ){
      std::string situ( "valid input " + std::to_string(d) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( Approx( d ) == argument::extract< CCCCR::CISOTX::Card4::Ecapt
                                                               >( iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(argument::extract< CCCCR::CISOTX::Card4::Ecapt >( iss ));
      }
    } // WHEN

    for( double d : {-10.0, -1.0, -0.1} ){
      std::string situ( "invalid input " + std::to_string(d) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS(argument::extract< CCCCR::CISOTX::Card4::Ecapt >(iss));
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
