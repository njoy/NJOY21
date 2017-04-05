#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ndir output values",
         "[ACER],[Card2], [Suff]"){

  long ln{0};
  GIVEN( "valid suff values" ){
    std::vector<double> validValues{0.0, .01, .70, .80, -.01, -.00};

    THEN( "the returned class has the correct value" ){
      for( auto& suff : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(suff) ) );

        REQUIRE( 
          suff == argument::extract< ACER::Card2::Suff >( iss ).value );
      }
    }
  }
  GIVEN( "no suff values" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss(
          std::istringstream( " /" ) );
      REQUIRE( ACER::Card2::Suff::defaultValue() == 
                argument::extract< ACER::Card2::Suff >( iss ).value );
    }
  }
  
  GIVEN( "invalid suff values" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss(
          std::istringstream( "abc" ) );
      REQUIRE_THROWS( argument::extract< ACER::Card2::Suff >( iss ) );
    }
  }

}

