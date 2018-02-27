#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card8b, Ek",
          "[ERRORR] [Normal] [Card8b] [Ek]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 1.0 10.0 100.0 /" ) );
      std::vector<double> inp{0.1, 1.0, 10.0, 100.0};

      THEN( "the values can be verified" ){
        auto ek =
                argument::extract< ERRORR::Normal::Card8b::Ek >( iss, 4 ).value;

        REQUIRE( ek.size() == inp.size() );

        for( size_t i = 0; i < inp.size(); i++ ){
          REQUIRE( inp.at(i)*dimwits::electronVolt == ek.at(i) );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no values are provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card8b::Ek >(
                                                                     iss, 0 ) );
      }
    } // WHEN

    WHEN( "fewer values than expected are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 1.0 10.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card8b::Ek >(
                                                                     iss, 4 ) );
      }
    } // WHEN

    WHEN( "a value is repeated" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 1.0 10.0 10.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card8b::Ek >(
                                                                     iss, 4 ) );
      }
    } // WHEN

    WHEN( "values aren't in ascending order" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 10.0 1.0 100.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card8b::Ek >(
                                                                     iss, 4 ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " -1.0 0.1 1.0 10.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card8b::Ek >(
                                                                     iss, 4 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
