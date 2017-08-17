#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card15 oe input values",
  "[LEAPR], [Card15], [Oe]" ){
  GIVEN( "a small value for nd" ){
    Argument< LEAPR::Card14::Nd > nd;
    nd.value = 3;

    WHEN( "there are the correct number of oes and they are valid" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0 3.0") );

      THEN( "the oe values can be extracted correctly" ){
        auto oes = argument::extract< 
          LEAPR::Card15::Oe >(iss, nd);
          std::vector< dimwits::Quantity< dimwits::ElectronVolts > > refOes{ 
            1.0 * dimwits::electronVolts,  
            2.0 * dimwits::electronVolts,
            3.0 * dimwits::electronVolts };
        REQUIRE( refOes == oes.value );
      } // THEN
    } // WHEN
    WHEN( "the oe values are invalid" ){
      iRecordStream< char> iss( std::istringstream("-1.0 2.0 3.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card15::Oe >( iss, nd ) );
      } // THEN
    } // WHEN
    WHEN( "the oe values are not in increasing order" ){
      iRecordStream< char> iss( std::istringstream("1.0 3.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card15::Oe >( iss, nd ) );
      } // THEN
    } // WHEN
    WHEN( "too few oe values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract<
          LEAPR::Card15::Oe >( iss, nd ) );
      } // THEN
    } // WHEN
    WHEN( "too many oe values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0 3.0 4.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_NOTHROW( argument::extract<
          LEAPR::Card15::Oe >( iss, nd ) );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "a larger value for nd" ){
    Argument< LEAPR::Card14::Nd > nd;
    nd.value = 7;

    WHEN( "there are the correct number of oes and they are valid" ){
      iRecordStream< char> iss( std::istringstream(
      ".010 .015 .025 .035\n"
      "2.5e-1 3.3e-1  5.04e-1/"
      ) );

      THEN( "the oe values can be extracted correctly" ){
        auto oes = argument::extract< 
          LEAPR::Card15::Oe >(iss, nd);
        std::vector< dimwits::Quantity< dimwits::ElectronVolts > > refOes{ 
          .01  * dimwits::electronVolts,
          .015 * dimwits::electronVolts, 
          .025 * dimwits::electronVolts,
          .035 * dimwits::electronVolts,
          .250 * dimwits::electronVolts,
          .330 * dimwits::electronVolts,
          .504 * dimwits::electronVolts };
        REQUIRE( refOes == oes.value );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
