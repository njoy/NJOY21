#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21;

SCENARIO( "Screamcase label" ){

  std::string moderInput(
    "1 -22 \n"
    "'my simple pendf tape'\n"
    "21 125\n"
    "0/\n" );

  std::string reconrInput(
    " 21 22\n"
    "'This is a sample Card2'\n"
    " 1306 0 0\n"
    "0.005 0 0.1 5e-07\n"
    "0/\n" );
  
  input::iRecordStream<char> iss( std::istringstream(
				    moderInput
				    + "RECONR\n"
                                    + reconrInput 
                                    + "GROUPR\n" ) );
  std::unordered_set< std::string > permittedRoutines = { "MODER", "RECONR" };
  std::ostringstream sink;
  std::string label("MODER");
  legacy::Sequence::Factory myFactory( sink, permittedRoutines );
  auto mySequence = myFactory( label, iss );
  REQUIRE( label == "GROUPR" );
  REQUIRE( sink.str() == moderInput + reconrInput );
}
