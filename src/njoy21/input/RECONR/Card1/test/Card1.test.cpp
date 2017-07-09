#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "RECONR Card1 input" ){
  GIVEN( "valid Card1 inputs" ){
    std::vector<std::pair<int, int>> validCard1Pairs{ {20, 21},
                                                      {21, 22},
                                                      {41, 42} };
    THEN( "Card1's can be created" ){
      for( auto& card1Pair : validCard1Pairs ){
        iRecordStream<char> iss
	  ( std::istringstream( std::to_string(card1Pair.first) + " " +
                                std::to_string(card1Pair.second) ) );
        RECONR::Card1 card1 (iss );
        AND_THEN( "the members can be tested" ){
          REQUIRE( card1Pair.first == card1.nendf.value );
          REQUIRE( card1Pair.second == card1.npend.value );
        }
      }
    }
  }

  GIVEN( "invalid Card1 inputs" ){
    // Note we don't have to test for all possible invalid Nendf and Npend
    // as those are tested in their respective classes/tests.
    {
      iRecordStream<char> stream( std::istringstream("   -20 21") );
      REQUIRE_THROWS( RECONR::Card1( stream ) );
    }{
      iRecordStream<char> stream( std::istringstream("   -20 -20") );
      REQUIRE_THROWS( RECONR::Card1( stream ) );
    }
  }
} // SCENARIO
