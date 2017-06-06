#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying GROUPR Card8b input", "[GROUPR], [Card8b]" ){
  WHEN( "valid Wght argument is given" ){
    std::string sTAB1 = " 0. 0. 0 0 1 6\n"
 "6 5\n"
 "1.00000E-05 8.00000E-20 1.00000E+03 9.13415E-10 1.00000E+04 6.13955E-08\n"
 "1.00925E+04 6.17490E-08 1.01859E+04 6.09190E-08 1.02802E+04 6.19874E-08\n";

    THEN( "the returned TAB1 has the correct values" ){
      iRecordStream<char> iss( ( std::istringstream( sTAB1 ) ) );

      REQUIRE_NOTHROW( GROUPR::Card8b( iss ) );
    }
  }
  WHEN( "invalid Wght argument is given" ){
    std::string sTAB1 = " 0. 0. 0 0 2 6\n"
 "6 5\n"
 "1.00000E-05 8.00000E-20 1.00000E+03 9.13415E-10 1.00000E+04 6.13955E-08\n"
 "1.00925E+04 6.17490E-08 1.01859E+04 6.09190E-08 1.02802E+04 6.19874E-08\n";

    THEN( "the returned TAB1 has the correct values" ){
      iRecordStream<char> iss( ( std::istringstream( sTAB1 ) ) );

      REQUIRE_THROWS( GROUPR::Card8b( iss ) );
    }
  }
}
