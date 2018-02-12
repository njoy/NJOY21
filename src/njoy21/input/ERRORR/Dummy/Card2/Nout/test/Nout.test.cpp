#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Dummy, Card2, Nout",
          "[ERRORR] [Dummy] [Card2] [Nout]" ){
  const int nin = 47;
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( auto i : {-99, -44, -20, 20, 92, 99} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< ERRORR::Dummy::Card2::Nout >(
                                                             iss, nin ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Dummy::Card2::Nout >(
                                                                   iss, nin ) );
      }
    } // WHEN

    WHEN( "invalid values are provided" ){
      for( auto i : {-100, -47, -19, 0, 19, 47, 100} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Dummy::Card2::Nout >(
                                                                   iss, nin ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
