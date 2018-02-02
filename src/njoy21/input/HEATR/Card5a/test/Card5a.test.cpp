#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

extern std::function< njoy::ENDFtk::TAB1() > makeTAB1;

SCENARIO( "Verifying HEATR Card5a input", 
  "[HEATR], [Card5a]" ){
  GIVEN( "a valid tab1 input" ){
    std::string tab1 = " 0. 0. 0 0 1 6\n"
    "6 5\n"
    "1.00000E-05 8.00000E-20 1.00000E+03 9.13415E-10 1.00000E+04 6.13955E-08\n"
    "1.00925E+04 6.17490E-08 1.01859E+04 6.09190E-08 1.02802E+04 6.19874E-08\n";

    std::string tab2 = 
      "0 0 0 0 2 4\n"
      "2 1 4 2\n" 
      "0.5 1.5 2 1.8 3 1.9 4 2.0\n";

    iRecordStream<char> iss1( ( std::istringstream( tab1 ) ) );
    iRecordStream<char> iss2( ( std::istringstream( tab2 ) ) );
    
    THEN( "the returned values are correct" ){
      {
        HEATR::Card5a card5a( iss1 );

        REQUIRE( 1 == card5a.qbar.value.NR() ); 
        REQUIRE( 6 == card5a.qbar.value.NP() );

        std::vector<double> X{1.00000E-05, 1.00000E+03, 1.00000E+04, 
                              1.00925E+04, 1.01859E+04, 1.02802E+04};
        std::vector<double> Y{8.00000E-20, 9.13415E-10, 6.13955E-08,
                              6.17490E-08, 6.09190E-08, 6.19874E-08};

        REQUIRE( ranges::equal(X, card5a.qbar.value.x()) );
        REQUIRE( ranges::equal(Y, card5a.qbar.value.y()) );
      }  
      {
        HEATR::Card5a card5a( iss2 );

        REQUIRE( 2 == card5a.qbar.value.NR() ); 
        REQUIRE( 4 == card5a.qbar.value.NP() );
    
    	std::vector<double> X{0.5, 2.0, 3.0, 4.0};
        std::vector<double> Y{1.5, 1.8, 1.9, 2.0};

        REQUIRE( ranges::equal(X, card5a.qbar.value.x()) );
        REQUIRE( ranges::equal(Y, card5a.qbar.value.y()) );
      }  
    } // THEN
  } // GIVEN
  GIVEN( "an invalid tab1 input" ){
    WHEN( "the first x-value is not positive" ){
      std::string tab1 = 
        "0 0 0 0 2 4\n"
        "2 1 4 2\n" 
        "0 1.5 2 1.8 3 1.9 4 2.0\n";
      iRecordStream<char> iss( ( std::istringstream( tab1 ) ) );
      THEN( "an exception is thrown" ){
	REQUIRE_THROWS( HEATR::Card5a( iss ) );
      } // THEN
    } // WHEN
    WHEN( "conflicting entries" ){
      std::string tab1 =
        "0 0 0 0 2 6\n"
        "2 1 4 2\n" 
        "1 1.5 2 1.8 3 1.9 4 2.0\n";
      std::string tab2 =
        "0 0 0 0 3 4\n"
        "2 1 4 2\n" 
        "1 1.5 2 1.8 3 1.9 4 2.0\n";
      iRecordStream<char> iss1( ( std::istringstream( tab1 ) ) );
      iRecordStream<char> iss2( ( std::istringstream( tab2 ) ) );

      THEN( "an exception is thrown" ){
	REQUIRE_THROWS( HEATR::Card5a( iss1 ) );
	REQUIRE_THROWS( HEATR::Card5a( iss2 ) );

      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
