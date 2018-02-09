#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

extern std::function< njoy::ENDFtk::TAB1() > makeTAB1;

SCENARIO( "Verifying HEATR Card5a input", "[HEATR], [Card5a]" ){
  GIVEN( "a valid tab1 input" ){
    SECTION( "formatted "){
      iRecordStream<char>
        iss( std::istringstream
             (" 0. 0. 0 0 1 6\n"
              "6 5\n"
              "1.00000E-05 8.00000E-20 1.00000E+03 9.13415E-10 1.00000E+04 6.13955E-08\n"
              "1.00925E+04 6.17490E-08 1.01859E+04 6.09190E-08 1.02802E+04 6.19874E-08\n" ) );

      HEATR::Card5a card5a( iss );

      REQUIRE( 1 == card5a.qbar.value.NR() );
      REQUIRE( 6 == card5a.qbar.value.NP() );

      std::vector<double> x{1.00000E-05, 1.00000E+03, 1.00000E+04,
                            1.00925E+04, 1.01859E+04, 1.02802E+04};
      std::vector<double> y{8.00000E-20, 9.13415E-10, 6.13955E-08,
                            6.17490E-08, 6.09190E-08, 6.19874E-08};

      REQUIRE( ranges::equal(x, card5a.qbar.value.x()) );
      REQUIRE( ranges::equal(y, card5a.qbar.value.y()) );
    }

    SECTION( "unformatted" ){
      iRecordStream<char>
        iss( std::istringstream
             ( "0 0 0 0 2 4\n"
               "2 1 4 2\n"
               "0.5 1.5 2 1.8 3 1.9 4 2.0\n" ) );
      HEATR::Card5a card5a( iss );

      REQUIRE( 2 == card5a.qbar.value.NR() );
      REQUIRE( 4 == card5a.qbar.value.NP() );

      std::vector<double> x{0.5, 2.0, 3.0, 4.0};
      std::vector<double> y{1.5, 1.8, 1.9, 2.0};

      REQUIRE( ranges::equal(x, card5a.qbar.value.x()) );
      REQUIRE( ranges::equal(y, card5a.qbar.value.y()) );
    }
  } // GIVEN
  
  GIVEN( "an invalid tab1 input" ){
    WHEN( "the first x-value is not positive" ){
      iRecordStream<char>
        iss( std::istringstream
             ( "0 0 0 0 2 4\n"
               "2 1 4 2\n"
               "0 1.5 2 1.8 3 1.9 4 2.0\n" ) );
      
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( HEATR::Card5a( iss ) );
      } // THEN
    } // WHEN
    
    WHEN( "too many interpolation regions" ){
      iRecordStream<char>
        iss( std::istringstream
             ( "0 0 0 0 2 6\n"
               "2 1 4 2\n"
               "1 1.5 2 1.8 3 1.9 4 2.0\n" ) );

      REQUIRE_THROWS( HEATR::Card5a( iss ) );
    }

    WHEN( "too many interpolation entries" ){
      iRecordStream<char>
        iss( std::istringstream
             ( "0 0 0 0 3 4\n"
               "2 1 4 2\n"
               "1 1.5 2 1.8 3 1.9 4 2.0\n" ) );

      REQUIRE_THROWS( HEATR::Card5a( iss ) );
    } // WHEN
  } // GIVEN
} // SCENARIO
