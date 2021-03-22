#define CATCH_CONFIG_MAIN

#include <iostream>

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21;

SCENARIO( "Legacy Sequence can be constructed" ){

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

  std::istringstream mockInput( moderInput
                                + "RECONR\n"
                                + reconrInput 
                                + "GROUPR\n" );

  auto cin_buffer = std::cin.rdbuf();
  std::cin.rdbuf( mockInput.rdbuf() );
  
  auto manager = io::Manager::Builder().construct();

  std::ostringstream mockBuffer;
  auto buffer_buffer = manager.buffer().rdbuf();
  manager.buffer().rdbuf( mockBuffer.rdbuf() );
    
  std::unordered_set< std::string > permittedRoutines = { "MODER", "RECONR" };
  std::string label("MODER");

  legacy::Sequence::Factory myFactory( manager, permittedRoutines );
  auto mySequence = myFactory( label );

  CHECK( label == "GROUPR" );
  CHECK( mockBuffer.str() == moderInput + reconrInput );

  std::cin.rdbuf( cin_buffer );
  manager.buffer().rdbuf( buffer_buffer );
}
