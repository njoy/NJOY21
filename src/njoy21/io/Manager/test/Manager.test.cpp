#define CATCH_CONFIG_MAIN

#include <regex>

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21;

bool compareFiles(const std::string& p1, const std::string& p2);

SCENARIO("An io manager can be constructed using a builder"){
  std::string sink;
  {
    auto myManager = io::Manager::Builder().input("./helloworld.txt")
                                           .output("./output")
                                           .construct();
  
    std::getline( myManager.input(), sink );
    REQUIRE( sink == "hello world" );
  
    myManager.buffer() << "20 21";
    auto fileGaurd = myManager.output(static_cast<legacy::Sequence*>(nullptr));
    njoy_c_MODER();
  }
  REQUIRE( compareFiles("./output", "./referenceOutput") );
  std::remove( "./output" );
  std::remove( "./tape21" );
}

bool compareFiles( const std::string& trialPath,
		   const std::string& referencePath ) {

  std::ifstream trialStream( trialPath, std::ifstream::binary );
  std::ifstream referenceStream( referencePath, std::ifstream::binary );
  
  if ( trialStream.fail() || referenceStream.fail() ) { return false; }

  auto trial =
    std::regex_replace
      ( std::string
        ( std::istreambuf_iterator<char>( trialStream.rdbuf() ),
           std::istreambuf_iterator<char>() ),
        std::regex("\\d\\.\\ds"), "0.0s" );

  std::string reference
    ( std::istreambuf_iterator<char>( referenceStream.rdbuf() ),
      std::istreambuf_iterator<char>() );

  return std::equal( trial.begin(), trial.end(), reference.begin() );
}
