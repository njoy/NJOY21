#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card5 inputs",
          "[RESXSR], [Card5]" ){

  GIVEN( "valid inputs" ){

    std::vector< std::string > hmatList{ "''", "'12345'", "'12345678'" };

    std::vector< std::string > matList{ " 0", " 10", " 9999" };

    std::vector< std::string > unitList{ " 20", " 44", " 99" };

    WHEN( "any combination of valid inputs is used" ){

      for( auto hmat : hmatList ){
        for( auto mat : matList ){
          for( auto unit : unitList ){
            iRecordStream<char> issCard5( std::istringstream(
                                          hmat + mat + unit + " /" ) );

            THEN( "no exception is thrown" ){
              REQUIRE_NOTHROW( RESXSR::Card5( issCard5 ) );
            }
          }
        }
      }
    } // WHEN

    WHEN( "verifiable inputs" ){
      iRecordStream<char> issCard5( std::istringstream( " 'text' 3929 88 /" ) );

      RESXSR::Card5 card5( issCard5 );

      THEN( "the values can be verified" ){
        REQUIRE( "text" == card5.hmat.value );
        REQUIRE( 3929 == card5.mat.value );
        REQUIRE( 88 == card5.unit.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){

    WHEN( "the hmat value is invalid" ){

      iRecordStream<char> issCard5( std::istringstream(
                                    " '123456789' 3929 88 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR::Card5( issCard5 ) );
      }
    }

    WHEN( "the mat value is invalid" ){

      iRecordStream<char> issCard5( std::istringstream(
                                    " 'text' 10000 88 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR::Card5( issCard5 ) );
      }
    }

    WHEN( "the unit value is invalid" ){

      iRecordStream<char> issCard5( std::istringstream(
                                    " 'text' 3929 19 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR::Card5( issCard5 ) );
      }
    }

    WHEN( "fewer values than expected are provided" ){

      iRecordStream<char> issCard5( std::istringstream(
                                    " 'text' 3929 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR::Card5( issCard5 ) );
      }
    }

    WHEN( "an extra value is provided" ){

      iRecordStream<char> issCard5( std::istringstream(
                                    " 'text' 3929 88 'farm' /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR::Card5( issCard5 ) );
      }
    }
  } // GIVEN
} // SCENARIO
      
