#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

extern std::function< njoy::ENDFtk::TAB1() > makeTAB1;

SCENARIO( "HEATR qbar values",
  "[HEATR], [Card5a], [Qbar]"){
  GIVEN( "a valid tab1 input" ){
    THEN( "the returned values are correct" ){
      SECTION("formatted"){
        iRecordStream<char>
          iss( std::istringstream
               ( " 0. 0. 0 0 1 6\n"
                 "6 5\n"
                 "1.00000E-05 8.00000E-20 1.00000E+03 9.13415E-10 1.00000E+04 6.13955E-08\n"
                 "1.00925E+04 6.17490E-08 1.01859E+04 6.09190E-08 1.02802E+04 6.19874E-08\n" ) );

        njoy::ENDFtk::TAB1 tab1 =
          argument::extract< HEATR::Card5a::Qbar >( iss ).value;

        REQUIRE( 1 == tab1.NR() );
        REQUIRE( 6 == tab1.NP() );

        std::vector<double> x{1.00000E-05, 1.00000E+03, 1.00000E+04,
                              1.00925E+04, 1.01859E+04, 1.02802E+04};
        std::vector<double> y{8.00000E-20, 9.13415E-10, 6.13955E-08,
                              6.17490E-08, 6.09190E-08, 6.19874E-08};

        REQUIRE( ranges::equal(x, tab1.x()) );
        REQUIRE( ranges::equal(y, tab1.y()) );
      }

      SECTION("unformatted"){
        iRecordStream<char>
          iss( std::istringstream
               ( "0 0 0 0 2 4\n"
                 "2 1 4 2\n"
                 "0.5 1.5 2 1.8 3 1.9 4 2.0\n" ) );

        njoy::ENDFtk::TAB1 tab1 =
          argument::extract< HEATR::Card5a::Qbar >( iss ).value;

        REQUIRE( 2 == tab1.NR() );
        REQUIRE( 4 == tab1.NP() );

        std::vector<double> x{0.5, 2.0, 3.0, 4.0};
        std::vector<double> y{1.5, 1.8, 1.9, 2.0};

        REQUIRE( ranges::equal( x, tab1.x() ) );
        REQUIRE( ranges::equal( y, tab1.y() ) );
      }
    } // THEN
  } // GIVEN

  GIVEN( "an invalid tab1 input" ){
    WHEN( "the first x-value is not positive" ){
      iRecordStream<char>
        iss( std::istringstream
             ( "0 0 0 0 2 4\n"
               "2 1 4 2\n"
               "0 1.5 2 1.8 3 1.9 4 2.0\n" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< HEATR::Card5a::Qbar >( iss ) );
      } // THEN
    } // WHEN

    WHEN( "conflicting entries" ){
      SECTION("too many interpolation regions"){
        iRecordStream<char>
          iss( std::istringstream
               ( "0 0 0 0 2 6\n"
                 "2 1 4 2\n"
                 "1 1.5 2 1.8 3 1.9 4 2.0\n" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< HEATR::Card5a::Qbar >( iss ) );
        }
      }

      SECTION("too many interpolation entries"){
        iRecordStream<char>
          iss( std::istringstream
               ( "0 0 0 0 3 4\n"
                 "2 1 4 2\n"
                 "1 1.5 2 1.8 3 1.9 4 2.0\n" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< HEATR::Card5a::Qbar >( iss ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
