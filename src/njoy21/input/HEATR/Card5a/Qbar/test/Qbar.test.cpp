#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

extern std::function< njoy::ENDFtk::UnivariateTabulation() > makeTAB1;

SCENARIO( "HEATR qbar values",
  "[HEATR],[Card5a], [Qbar]"){
  std::string tab1 =
  " 0.000000+0 0.000000+0         33          0          1          49228"
    "1460  438\n"
  "          4          4                                            9228"
    "1460  439\n"
  " 1.000000+1 1.725000+1 1.500000+1 1.850000+1 1.900000+1 1.975000+09228"
    "1460  440\n"
  " 2.700000+1 1.605000+1                                            9228"
    "1460  441\n";

  std::string tab2 = 
    "0. 0. 0 0 1 8\n"
    "8 2\n"
    "8.0e6 -8.14e6 9.0e6 -8.14e6 1.1e7 -8.38e6\n"
    "1.2e7 -8.74e6 1.3e7 -1.03e7 1.4e7 -1.091e7\n"
    "1.5e7 -1.11e7 2.0e7 -1.125e7/";
  iRecordStream<char> iss( std::istringstream( tab2 ) );
  auto qbar = argument::extract< HEATR::Card5a::Qbar >( iss );

	
//  auto tab1 = makeTAB1();
//  std::vector< double > xValues{ 1.0, 2.0, 3.0 }; 
// for ( long index = 0; index < tab1.NP(); ++index ){
//    REQUIRE( xValues[ index ] == tab1.x().at( index ) );
//    REQUIRE( xValues[ index ] == tab1.x()[ index ] );
//  }
  REQUIRE( true );

} // SCENARIO
