#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Iopt output values",
         "[ACER],[Card2], [Iopt]"){

  long ln{0};
  GIVEN( "valid Iopt parameters" ){
    std::vector<int> validValues{-8,-7,-5,-4,-3,-2,-1, 1,2,3,4,5,7,8};

    THEN( "the returned class has the correct value" ){
      for( auto iopt : validValues ){
        iRecordStream<char> issIopt( 
            std::istringstream( std::to_string( iopt ) ) );

        REQUIRE( iopt == argument::extract< ACER::Card2::Iopt >( 
                          issIopt ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Iopt parameters" ){
    std::vector<int> invalidValues{-10, -9, -6, 0, 6, 9, 10};

    THEN( "the returned class has the correct value" ){
      for( auto iopt : invalidValues ){
        iRecordStream<char> issIopt( 
            std::istringstream( std::to_string( iopt ) ) );

        REQUIRE_THROWS( argument::extract< ACER::Card2::Iopt >( issIopt ) );
      }
    }
  } // GIVEN
} // SCENARIO

