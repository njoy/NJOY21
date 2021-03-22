#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Log.hpp"

namespace njoy{
namespace njoy21{

struct CommandLine;

#include "njoy21/Version.hpp"

} // namespace njoy21
} // namespace njoy

#include "njoy21/CommandLine.hpp"

using namespace njoy::njoy21;

char** argv( std::vector< std::string >& args ){
  static std::vector< char* > argv;
  for ( auto& arg : args ){ argv.push_back( &(arg.front()) ); }
  return &( argv.front() );
}

SCENARIO( "Parsing a command-line interface for options and flags" ){
  GIVEN( "An instance of the Commandline with no args" ){
    std::vector< std::string > arguments = { "njoy21", "--help"};

    CommandLine CL( arguments.size(), argv(arguments) );
    REQUIRE( not CL.inputPath );
    REQUIRE( not CL.outputPath );
    REQUIRE( not CL.legacySwitch );
    REQUIRE( not CL.verifyOnly );    
  }
  GIVEN( "An instance of the Commandline with an input path" ){
    std::vector< std::string > arguments = { "njoy21", "--input", "/my/path" };

    CommandLine CL( arguments.size(), argv(arguments) );
    njoy::Log::debug( *(CL.inputPath) );
    REQUIRE( *(CL.inputPath) == "/my/path");
  }
}
