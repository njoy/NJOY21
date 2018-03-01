#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card7, Efmean",
          "[ERRORR] [Normal] [Card7] [Efmean]" ){
  GIVEN( "valid inputs" ){
    for( double d :
                  {0.0, 1.0, 1.0e1, 1.0e2, 1.0e3, 1.0e4, 1.0e5, 1.0e6, 1.0e7} ){
      std::string situ( "valid value " + std::to_string(d) + " is provided." );
      WHEN( situ.c_str() ){
        const int mfcov = 35;
        const int ifissp = -1;
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( d*dimwits::electronVolt == *( argument::extract<
                ERRORR::Normal::Card7::Efmean >( iss, ifissp, mfcov ).value ) );
        }
      } // WHEN
    }

    for( auto i : {31, 33, 34, 40} ){
      std::string situ( "mfcov == " + std::to_string(i) );
      WHEN( situ.c_str() ){
        const int ifissp = -1;
        iRecordStream<char> iss( std::istringstream( " -10.0 /" ) );

        THEN( "the value doesn't matter, but can be verified" ){
          REQUIRE( -10.0*dimwits::electronVolt == *( argument::extract<
                    ERRORR::Normal::Card7::Efmean >( iss, ifissp, i ).value ) );
        }
      } // WHEN
    }

    WHEN( "no value is provided with ifissp = -1" ){
      const int mfcov = 35;
      const int ifissp = -1;
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is provided" ){
        REQUIRE( 2.0e6*dimwits::electronVolt == *( argument::extract<
                ERRORR::Normal::Card7::Efmean >( iss, ifissp, mfcov ).value ) );
      }
    } // WHEN

    WHEN( "no value is provided, but ifissp != -1" ){
      const int mfcov = 35;
      const int ifissp = 1;
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "no default value is provided" ){
        REQUIRE( std::nullopt == argument::extract<
                  ERRORR::Normal::Card7::Efmean >( iss, ifissp, mfcov ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( double d : {-0.1, -1.0, -10.0, -1.0e2} ){
      std::string situ( "invalid value " + std::to_string(d) + " is provided.");
      WHEN( situ.c_str() ){
        const int mfcov = 35;
        const int ifissp = -1;
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card7::Efmean >(
                                                         iss, ifissp, mfcov ) );
        }
      } // WHEN
    }
  } // GIVEN
} // SCENARIO
