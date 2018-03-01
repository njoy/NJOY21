#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card9, Akxy",
          "[ERRORR] [Normal] [Card9] [Akxy]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1.0 0.0 0.0 -1.0 /" ) );
      std::vector<double> inp{1.0, 0.0, 0.0, -1.0};

      THEN( "the values can be verified" ){
        auto akxy = argument::extract< ERRORR::Normal::Card9::Akxy >(
                                                              iss, 4, 3 ).value;

        REQUIRE( inp == akxy );
      }
    } // WHEN

    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );
      const size_t num_vals = 4;

      THEN( "the default value can be verified" ){
        for( size_t i = 0; i < num_vals; i++ ){
          std::vector<double> ref(num_vals, 0.0);
          ref.at(i) = 1.0;

          REQUIRE( ref == argument::extract< ERRORR::Normal::Card9::Akxy >(
                                                     iss, num_vals, i ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 1.0 2.0 1.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card9::Akxy >(
                                                                  iss, 4, 1 ) );
      }
    } // WHEN

    WHEN( "the diag value is greater than the number of values" ){
      iRecordStream<char> iss( std::istringstream( " 1.0 0.0 1.0 0.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card9::Akxy >(
                                                                  iss, 4, 4 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
