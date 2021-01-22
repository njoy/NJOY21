#define CATCH_CONFIG_MAIN

#include <iostream>

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21;

SCENARIO( "Modern Sequence can be constructed" ){

  std::string reconrInput(
    " 21 22\n"
    "'This is a sample Card2'\n"
    " 1306 0 0\n"
    "0.005 0 0.1 5e-07\n"
    "0/\n" );

  std::istringstream mockInput( reconrInput + "GROUPR\n" );

  auto cin_buffer = std::cin.rdbuf();
  std::cin.rdbuf( mockInput.rdbuf() );
  
  auto manager = io::Manager::Builder().construct();

  std::ostringstream mockBuffer;
  auto buffer_buffer = manager.buffer().rdbuf();
  manager.buffer().rdbuf( mockBuffer.rdbuf() );
    
  std::unordered_set< std::string > permittedRoutines = { "RECONR" };
  std::string label("RECONR");

  modern::Sequence::Factory myFactory( manager, permittedRoutines );
  auto mySequence = myFactory( label );

  CHECK( label == "GROUPR" );
  CHECK( mockBuffer.str() == reconrInput );

  std::cin.rdbuf( cin_buffer );
  manager.buffer().rdbuf( buffer_buffer );
}
