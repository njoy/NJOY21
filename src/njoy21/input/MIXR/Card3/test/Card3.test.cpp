#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MIXR, Card3",
          "[MIXR] [Card3]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream(
                                             " 816 0.2 9235 0.3 9439 0.5 /" ) );

      THEN( "the values can be verified" ){
        MIXR::Card3 card3( iss );

        REQUIRE( 3 == card3.matnWtnList.size() );

        REQUIRE( 816 == card3.matnWtnList.at( 0 ).first.value );
        REQUIRE( Approx( 0.2 ) == card3.matnWtnList.at( 0 ).second.value );

        REQUIRE( 9235 == card3.matnWtnList.at( 1 ).first.value );
        REQUIRE( Approx( 0.3 ) == card3.matnWtnList.at( 1 ).second.value );

        REQUIRE( 9439 == card3.matnWtnList.at( 2 ).first.value );
        REQUIRE( Approx( 0.5 ) == card3.matnWtnList.at( 2 ).second.value );
      }
    } // WHEN

    WHEN( "the maximum number of values are provided" ){
      iRecordStream<char> iss( std::istringstream(
          " 1 0.1 2 0.2 3 0.3 4 0.4 5 0.5 6 0.6 7 0.7 8 0.8 9 0.9 10 1.0 /" ) );

      THEN( "the values can be verified" ){
        MIXR::Card3 card3( iss );

        for( int i = 0; i < 10; i++ ){
          REQUIRE( ( i + 1 ) == card3.matnWtnList.at( i ).first.value );
          REQUIRE( Approx( ( i+1 ) * 0.1 ) ==
                                       card3.matnWtnList.at( i ).second.value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no values are provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR::Card3( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream(
       " 1 0.1 2 0.2 3 0.3 4 0.4 5 0.5 6 0.6 7 0.7 8 0.8 9 0.9 10 1.0 11 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR::Card3( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 1 0.2 2 0.3 3 1.1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR::Card3( iss ) );
      }
    } // WHEN

    WHEN( "a material number is used more than once" ){
      iRecordStream<char> iss( std::istringstream( " 1 0.1 2 0.2 1 0.3 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR::Card3( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
