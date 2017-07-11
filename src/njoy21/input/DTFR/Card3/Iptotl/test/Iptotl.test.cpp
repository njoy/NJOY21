#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR iptotl values",
  "[DTFR],[Card3], [Iptotl]"){

  GIVEN( "valid iptotl values" ){
    std::vector<int> validValues{3, 4};

    THEN( "the returned class has the correct value" ){
      for( int iptotl : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string(iptotl) ) );
        REQUIRE( iptotl == argument::extract< 
          DTFR::Card3::Iptotl >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid iptotl values" ){
    std::vector<int> invalidValues{-3, 0, 2};

    THEN( "an exception is thrown" ){
      for( int iptotl : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string(iptotl) ) );
        REQUIRE_THROWS( argument::extract< 
          DTFR::Card3::Iptotl >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
