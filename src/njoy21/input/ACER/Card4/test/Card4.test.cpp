#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying ACER Card4 input",
          "[ACER], [Card4]" ){
  Argument< ACER::Card2::Nxtra > nxtra;
  nxtra.value = 3;

  std::vector< std::pair<int,double> > pairs{
    {1001, 0.999167},
    {2003, 2.990120},
    {92235, 233.02479} };

  GIVEN( "valid IZAW entries" ){
    iRecordStream<char> issIzaw( std::istringstream( 
      std::to_string( pairs[0].first ) + " " + std::to_string( pairs[0].second ) + " " +
      std::to_string( pairs[1].first ) + " " + std::to_string( pairs[1].second ) + " " +
      std::to_string( pairs[2].first ) + " " + std::to_string( pairs[2].second ) )
      );

    THEN( "the IZ,AW pairs can be extracted and verified" ){
      ACER::Card4 card4( issIzaw, nxtra );
      auto izaw = card4.izaw.value;
        for( size_t i=0; i<izaw.size(); i++ ){
          REQUIRE( izaw[i].first == pairs[i].first );
          REQUIRE( izaw[i].second == pairs[i].second );
        }
    }
  } // GIVEN 

  GIVEN( "invalid izaw---too few IZ,AW pairs" ){
    iRecordStream<char> issIzaw( std::istringstream( 
      std::to_string( pairs[0].first ) + " " + std::to_string( pairs[0].second ) + " " +
      std::to_string( pairs[1].first ) + " " + std::to_string( pairs[1].second ) )
      );
    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( ACER::Card4 card4( issIzaw, nxtra ) );
    }
  } // GIVEN

}
