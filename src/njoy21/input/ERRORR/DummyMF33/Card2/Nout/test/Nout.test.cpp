#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, DummyMF33, Card2, Nout",
          "[ERRORR] [DummyMF33] [Card2] [Nout]" ){
  const int nin = 47;
  GIVEN( "valid inputs" ){
    for( auto i : {-99, -44, -20, 20, 92, 99} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< ERRORR::DummyMF33::Card2::Nout >(
                                                             iss, nin ).value );
        }
      } // WHEN
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::DummyMF33::Card2::Nout >(
                                                                   iss, nin ) );
      }
    } // WHEN

    for( auto i : {-100, -47, -19, 0, 19, 47, 100} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::DummyMF33::Card2::Nout >(
                                                                   iss, nin ) );
        }
      } // WHEN
    }
  } // GIVEN
} // SCENARIO
