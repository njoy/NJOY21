#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR ipingp values",
  "[DTFR],[Card3], [Ipingp]"){
  GIVEN( "a valid iptotl value" ){
    Argument< DTFR::Card3::Iptotl >iptotl; iptotl.value = 6;
    WHEN( "ipingp value is valid" ){
      std::vector<int> validValues{7, 8};
      THEN( "the returned class has the correct value" ){
        for( auto& ipingp : validValues ){
          iRecordStream<char> iss(
	    std::istringstream( std::to_string(ipingp) ) );
          REQUIRE( ipingp == argument::extract< 
	    DTFR::Card3::Ipingp >( iss, iptotl ).value );
        }
      } // THEN
    } // WHEN

    WHEN( "ipingp value is invalid" ){
      std::vector<int> invalidValues{-1, 0, 4, 5};
      THEN( "an exception is thrown" ){
        for( auto& ipingp : invalidValues ){
          iRecordStream<char> iss( 
	    std::istringstream( std::to_string(ipingp) ) );
          REQUIRE_THROWS( argument::extract< 
            DTFR::Card3::Ipingp >( iss, iptotl ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
