#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR hdescr",
          "[COVR], [Card3c], [Hdescr]"){

  GIVEN( "valid (short) hdescr entry" ){
    WHEN( "a valid value is provided" ){
      for( std::string hdescr : {"", "1", "123456789012345678901"} ){
        std::string inp( std::string ("'") + hdescr + std::string( "' /" ) );
        iRecordStream<char> iss{ std::istringstream{ inp } };

        THEN( "the value can be verified" ){
          REQUIRE( hdescr == argument::extract< COVR::Card3c::Hdescr
                                                                >( iss ).value);
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid (long) hdescr values" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< COVR::Card3c::Hdescr >( iss ) );
      }
    } // WHEN

    WHEN( "an invalid (long) value is provided" ){
      iRecordStream<char> iss( std::istringstream( 
                                              "'123456789 123456789 12' /"  ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< COVR::Card3c::Hdescr >( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
