#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

char** argv( std::vector< std::string >& args ){
  static std::vector< char* > argv;
  for ( auto& arg : args ){ argv.push_back( &(arg.front()) ); }
  return &( argv.front() );
}

using namespace njoy::njoy21;

SCENARIO("run a simple njoy problem"){
  {
    std::vector< std::string > args = { 
      "./njoy21", "--input", "input.njoy", "--output", "output.txt" };
    Driver driver( args.size(), argv(args) );
    driver();
  }
  std::remove( "output.txt" );
}
