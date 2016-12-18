#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  Argument< BROADR::Card2::Ntemp2 > ntemp2; ntemp2.value = 1;
  Argument< BROADR::Card2::Istrap > istrap; istrap.value = 1;
  Argument< BROADR::Card2::Temp1 > temp1; temp1.value = 10.0 * dimwits::kelvin;
  {
    iRecordStream<char> iss( std::istringstream("   9.0") );
    REQUIRE_THROWS( argument::extract< BROADR::Card4::Temp2 >
		    ( iss, ntemp2, istrap, temp1 ) );
  }{
    iRecordStream<char> iss( std::istringstream("   10.0") );
    REQUIRE( argument::extract< BROADR::Card4::Temp2 >
	     ( iss, ntemp2, istrap, temp1 ).value.front()
	     == 10.0 * dimwits::kelvin );
  }{
    iRecordStream<char> iss( std::istringstream("   11.0") );
    REQUIRE( argument::extract< BROADR::Card4::Temp2 >
	     ( iss, ntemp2, istrap, temp1 ).value.front()
	     == 11.0 * dimwits::kelvin );
  }{
    iRecordStream<char> iss( std::istringstream("   ") );
    REQUIRE_THROWS( argument::extract< BROADR::Card4::Temp2 >
		    ( iss, ntemp2, istrap, temp1 ) );
  }{
    ntemp2.value = 2;
    iRecordStream<char> iss( std::istringstream("   100.0 200.0") );
    auto temp2 = argument::extract< BROADR::Card4::Temp2 >
                 ( iss, ntemp2, istrap, temp1 );
    REQUIRE( temp2.value.front() == 100.0 * dimwits::kelvin );
    REQUIRE( temp2.value.back() == 200.0 * dimwits::kelvin );
  }{
    ntemp2.value = 2;
    iRecordStream<char> iss( std::istringstream("   300.0 200.0") );
    REQUIRE_THROWS( argument::extract< BROADR::Card4::Temp2 >
		    ( iss, ntemp2, istrap, temp1 ) );
  }
}
