#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR itabl values",
  "[DTFR],[Card3], [Itabl]"){
  GIVEN( "valid iptotl and ng values" ){
    Argument< DTFR::Card3::Iptotl > iptotl; iptotl.value = 4;
    Argument< DTFR::Card3::Ng > ng; ng.value = 12;

    WHEN( "itabl input values are valid" ){
      std::vector<int> validValues{16, 17, 20};
      THEN( "the returned class has the correct value" ){
        for( int itabl : validValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string(itabl) ) );
          REQUIRE( itabl == argument::extract< 
            DTFR::Card3::Itabl >(iss, iptotl, ng).value );
        }
      } // THEN
    } // WHEN

    WHEN( "itabl values are invalid" ){
    std::vector<int> invalidValues{-1, 0, 15};
      THEN( "an exception is thrown" ){
        for( int itabl : invalidValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string(itabl) ) );
          REQUIRE_THROWS( argument::extract< 
            DTFR::Card3::Itabl >( iss, iptotl, ng ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
