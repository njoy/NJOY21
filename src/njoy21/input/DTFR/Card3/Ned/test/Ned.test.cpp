#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR ned values",
  "[DTFR],[Card3], [Ned]"){

  GIVEN( "a large iptotl value" ){
    Argument< DTFR::Card3::Iptotl >iptotl; iptotl.value = 6;
    WHEN( "The ned inputs are valid" ){
      std::vector<int> validValues{3, 4, 7, 8};
      THEN( "the returned class has the correct value" ){
        for( int ned : validValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string(ned) ) );
          REQUIRE( ned == argument::extract< 
            DTFR::Card3::Ned >( iss, iptotl ).value );
        } 
      } // THEN
    } // WHEN

    WHEN( "ned input values are invalid" ){
      std::vector<int> invalidValues{-1, 0, 2};
      THEN( "an exception is thrown" ){
        for( int ned : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string(ned) ) );
          REQUIRE_THROWS( argument::extract< 
            DTFR::Card3::Ned >( iss, iptotl ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "a smaller iptotl value" ){
    Argument< DTFR::Card3::Iptotl >iptotl; iptotl.value = 3;
    WHEN( "no ned input value is given" ){
      THEN( "default value is used" ){
        iRecordStream<char> iss( std::istringstream( " /" ) );
        REQUIRE( 0 == argument::extract< 
          DTFR::Card3::Ned >( iss, iptotl ).value );
      } // THEN
    } // WHEN 
  } // GIVEN
} // SCENARIO
