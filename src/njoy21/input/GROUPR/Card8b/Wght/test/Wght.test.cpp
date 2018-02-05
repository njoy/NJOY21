#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Wght input values", "[Card8b], [Wght]" ){
  GIVEN( "Valid pseudo-TAB1 input" ){
    std::string sTAB1 = " 0. 0. 0 0 1 6\n"
 "6 5\n"
 "1.00000E-05 8.00000E-20 1.00000E+03 9.13415E-10 1.00000E+04 6.13955E-08\n"
 "1.00925E+04 6.17490E-08 1.01859E+04 6.09190E-08 1.02802E+04 6.19874E-08\n";

    THEN( "the returned TAB1 has the correct values" ){
      iRecordStream<char> iss( ( std::istringstream( sTAB1 ) ) );

      njoy::ENDFtk::TAB1 TAB1 = argument::extract< 
          GROUPR::Card8b::Wght >( iss ).value;

      REQUIRE( 1 == TAB1.NR() );
      REQUIRE( 6 == TAB1.NP() );

      std::vector<double> X{1.00000E-05, 1.00000E+03, 1.00000E+04, 
                            1.00925E+04, 1.01859E+04, 1.02802E+04};
      std::vector<double> Y{8.00000E-20, 9.13415E-10, 6.13955E-08,
                            6.17490E-08, 6.09190E-08, 6.19874E-08};

      REQUIRE( ranges::equal(X, TAB1.x()) );
      REQUIRE( ranges::equal(Y, TAB1.y()) );
    }
  }

  GIVEN( "invalid pseudo-TAB1 input" ){
    WHEN( "energy value is negative" ){
      std::string sTAB1 = " 0. 0. 0 0 1 6\n"
   "6 5\n"
   "1.00000E-05 8.00000E-20 -1.00000E+03 9.13415E-10 1.00000E+04 6.13955E-08\n"
   "1.00925E+04 6.17490E-08 1.01859E+04  6.09190E-08 1.02802E+04 6.19874E-08\n";

      THEN( "an exception is thrown" ){
        iRecordStream<char> iss( ( std::istringstream( sTAB1 ) ) );

        REQUIRE_THROWS( argument::extract<GROUPR::Card8b::Wght >( iss ) );

      }
    } // WHEN
    WHEN( "wrong number of regions" ){
      std::string sTAB1 = " 0. 0. 0 0 2 6\n"
   "6 5\n"
   "1.00000E-05 8.00000E-20 1.00000E+03  9.13415E-10 1.00000E+04 6.13955E-08\n"
   "1.00925E+04 6.17490E-08 1.01859E+04  6.09190E-08 1.02802E+04 6.19874E-08\n";

      THEN( "an exception is thrown" ){
        iRecordStream<char> iss( ( std::istringstream( sTAB1 ) ) );

        REQUIRE_THROWS( argument::extract<GROUPR::Card8b::Wght >( iss ) );

      }
    } // WHEN
    WHEN( "wrong number of values" ){
      std::string sTAB1 = " 0. 0. 0 0 1 6\n"
   "6 5\n"
   "1.00000E-05 8.00000E-20 1.00000E+03  9.13415E-10 1.00000E+04 6.13955E-08\n"
   "1.00925E+04 6.17490E-08 1.01859E+04 \n";

      THEN( "an exception is thrown" ){
        iRecordStream<char> iss( ( std::istringstream( sTAB1 ) ) );

        REQUIRE_THROWS( argument::extract<GROUPR::Card8b::Wght >( iss ) );

      }
    } // WHEN
    WHEN( "weight value is negative" ){
      std::string sTAB1 = " 0. 0. 0 0 1 6\n"
   "6 5\n"
   "1.00000E-05 8.00000E-20 1.00000E+03 -9.13415E-10 1.00000E+04 6.13955E-08\n"
   "1.00925E+04 6.17490E-08 1.01859E+04  6.09190E-08 1.02802E+04 6.19874E-08\n";

      THEN( "an exception is thrown" ){
        iRecordStream<char> iss( ( std::istringstream( sTAB1 ) ) );

        REQUIRE_THROWS( argument::extract<GROUPR::Card8b::Wght >( iss ) );

      }
    } // WHEN
  }
} // SCENARIO
