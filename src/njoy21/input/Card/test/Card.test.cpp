#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "simple case" ){
  long lineNumber = 1;
  std::istringstream iss( "1 2 3 4" );
  iss.exceptions( std::ios_base::failbit | std::ios_base::badbit );
  REQUIRE( "1 2 3 4" == Card::extract( iss, lineNumber ).str() );
}

SCENARIO( "with quote" ){
  long lineNumber = 1;
  std::istringstream iss( "1 2 3 4 'Lorem Ipsum'" );
  iss.exceptions( std::ios_base::failbit | std::ios_base::badbit );
  REQUIRE( "1 2 3 4 'Lorem Ipsum'" == Card::extract( iss, lineNumber ).str() );
}

SCENARIO( "with line terminator" ){
  long lineNumber = 1;
  std::string base( "1 2 3 4 'Lorem Ipsum'" );
  std::string comment( "this is a comment" );
  std::istringstream iss( base + '/' + comment );
  iss.exceptions( std::ios_base::failbit | std::ios_base::badbit );
  REQUIRE( "1 2 3 4 'Lorem Ipsum'" == Card::extract( iss, lineNumber ).str() );
}

SCENARIO( "with unterminated quotation" ){
  long lineNumber = 1;
  std::istringstream iss( "1 2 3 4 'Lorem Ipsum" );
  iss.exceptions( std::ios_base::failbit | std::ios_base::badbit );
  REQUIRE_THROWS( Card::extract( iss, lineNumber ) );
}

SCENARIO( "no card to extract" ){
  long lineNumber = 1;
  std::istringstream iss( "" );
  iss.exceptions( std::ios_base::failbit | std::ios_base::badbit );
  REQUIRE_THROWS( Card::extract( iss, lineNumber ) );
}
