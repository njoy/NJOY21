#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card8a, Mts",
          "[ERRORR] [Normal] [Card8a] [Mts]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      std::vector<int> inp{1, 2, 4, 500, 1200, 9999};
      iRecordStream<char> iss( std::istringstream( " 1 2 4 500 1200 9999 /" ) );

      THEN( "the values can be verified" ){
        auto mts = argument::extract< ERRORR::Normal::Card8a::Mts >(
                                                        iss, inp.size() ).value;

        REQUIRE( mts.size() == inp.size() );

        for( size_t i = 0; i < inp.size(); i++ ){
          REQUIRE( mts.at(i) == inp.at(i) );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no values are provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card8a::Mts >(
                                                                     iss, 0 ) );
      }
    } // WHEN

     WHEN( "fewer values than expected are provided" ){
       iRecordStream<char> iss( std::istringstream( " 1 2 4 /" ) );

       THEN( "an exception is thrown" ){
         REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card8a::Mts >(
                                                                     iss, 4 ) );
       }
     } // WHEN

     WHEN( "an invalid value is provided" ){
       iRecordStream<char> iss( std::istringstream( " 1 2 4 500 10000 /" ) );

       THEN( "an exception is thrown" ){
         REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card8a::Mts >(
                                                                     iss, 5 ) );
       }
     } // WHEN

     WHEN( "an invalid value is provided" ){
       iRecordStream<char> iss( std::istringstream( " 0 2 4 500 1000 /" ) );

       THEN( "an exception is thrown" ){
         REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card8a::Mts >(
                                                                     iss, 5 ) );
       }
     } // WHEN

     WHEN( "a value is provided twice" ){
       iRecordStream<char> iss( std::istringstream( " 1 2 4 4 500 /" ) );

       THEN( "an exception is thrown" ){
         REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card8a::Mts >(
                                                                     iss, 5 ) );
       }
     } // WHEN

     WHEN( "values are provided out of order" ){
       iRecordStream<char> iss( std::istringstream( " 1 4 2 500 /" ) );

       THEN( "an exception is thrown" ){
         REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card8a::Mts >(
                                                                     iss, 4 ) );
       }
     } // WHEN
  } // GIVEN
} // SCENARIO
