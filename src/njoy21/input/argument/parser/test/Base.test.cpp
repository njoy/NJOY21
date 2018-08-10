#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input::argument::parser;

template< typename Char >
using iRecordStream = njoy::njoy21::input::iRecordStream<Char>;

SCENARIO("Base"){
  SECTION( "simple case" ){
    int sink = 0;
    iRecordStream<char> iss( std::istringstream("   101") );
    REQUIRE( Base< int >::read( iss, sink ) );
    REQUIRE( sink == 101 );
  }

  SECTION( "simple failing case" ){
    double sink = 0.0;
    iRecordStream<char> iss( std::istringstream("   100.abc") );
    Base< double >::read( iss, sink );
    REQUIRE( iss.fail() );
  }

  SECTION( "string" ){
    GIVEN("a string with quotes"){
      std::string sink = "";
      iRecordStream<char> iss( std::istringstream("   'Lorem Ipsum'") );
      THEN( "the string will be read successfully"){
        REQUIRE( Base< std::string >::read( iss, sink ) );
        AND_THEN("the string will be read until the matching quote"){
          REQUIRE( sink == "Lorem Ipsum" );
        }
      }
    }

    GIVEN("a string with quotes across multiple lines"){
      std::string sink = "";
      iRecordStream<char> iss( std::istringstream("   'Lorem \nIpsum'") );
      THEN( "the string will be read successfully"){
        REQUIRE( Base< std::string >::read( iss, sink ) );
        AND_THEN("the string will be read until the"
                 " matching quote with newlines stripped"){
          REQUIRE( sink == "Lorem Ipsum" );
        }
      }
    }

    GIVEN("a string with \" quotes"){
      std::string sink = "";
      iRecordStream<char> iss( std::istringstream("   \"Lorem Ipsum\"") );
      THEN( "the string will be read successfully"){
        REQUIRE( Base< std::string >::read( iss, sink ) );
        AND_THEN("the string will be read until the matching quote"){
          REQUIRE( sink == "Lorem Ipsum" );
        }
      }
    }

    GIVEN("a string with \" quotes across multiple lines"){
      std::string sink = "";
      iRecordStream<char> iss( std::istringstream("   \"Lorem \nIpsum\"") );
      THEN( "the string will be read successfully"){
        REQUIRE( Base< std::string >::read( iss, sink ) );
        AND_THEN("the string will be read until the"
                 " matching quote with newlines stripped"){
          REQUIRE( sink == "Lorem Ipsum" );
        }
      }
    }

    GIVEN("a string with * quotes"){
      std::string sink = "";
      iRecordStream<char> iss( std::istringstream("   *Lorem Ipsum*") );
      THEN( "the string will be read successfully"){
        REQUIRE( Base< std::string >::read( iss, sink ) );
        AND_THEN("the string will be read until the matching quote"){
          REQUIRE( sink == "Lorem Ipsum" );
        }
      }
    }

    GIVEN("a string with * quotes across multiple lines"){
      std::string sink = "";
      iRecordStream<char> iss( std::istringstream("   *Lorem \nIpsum*") );
      THEN( "the string will be read successfully"){
        REQUIRE( Base< std::string >::read( iss, sink ) );
        AND_THEN("the string will be read until the"
                 " matching quote with newlines stripped"){
          REQUIRE( sink == "Lorem Ipsum" );
        }
      }
    }

    SECTION("without quotes"){
      std::string sink = "";
      iRecordStream<char> iss( std::istringstream("   Lorem Ipsum ") );
      REQUIRE( Base< std::string >::read( iss, sink ) );
      REQUIRE( sink == "Lorem" );
      REQUIRE( not iss.fail() );
      std::getline( iss, sink );
      REQUIRE( sink == " Ipsum " );
    }

    SECTION("incomplete quotes"){
      std::string sink = "";
      iRecordStream<char> iss( std::istringstream("   'Lorem Ipsum ") );
      REQUIRE( Base< std::string >::read( iss, sink ) );
      REQUIRE( iss.fail() );
    }

    SECTION("incomplete * quotes"){
      std::string sink = "";
      iRecordStream<char> iss( std::istringstream("   *Lorem Ipsum ") );
      REQUIRE( Base< std::string >::read( iss, sink ) );
      REQUIRE( iss.fail() );
    }

    SECTION("incomplete \" quotes"){
      std::string sink = "";
      iRecordStream<char> iss( std::istringstream("   \"Lorem Ipsum ") );
      REQUIRE( Base< std::string >::read( iss, sink ) );
      REQUIRE( iss.fail() );
    }

    SECTION("trailing slash"){
      std::string sink = "";
      iRecordStream<char> iss( std::istringstream(" hello/world ") );
      REQUIRE( Base< std::string >::read( iss, sink ) );
      REQUIRE( sink == "hello" );
      REQUIRE( not iss.fail() );
      std::getline( iss, sink );
      REQUIRE( sink == "/world " );
    }
  }

  SECTION( "Quantity" ){
    dimwits::Quantity< dimwits::Meter > sink = 0 * dimwits::meter;
    iRecordStream<char> iss( std::istringstream("   10 ") );
    REQUIRE( Base< dimwits::Quantity
             < dimwits::Meter > >::read( iss, sink ) );
    REQUIRE( sink == 10 * dimwits::meter );
  }

  SECTION( "Pair" ){
    using MyPair = std::pair< int, double >;
    MyPair sink{0, 1.0};
    iRecordStream<char> iss( std::istringstream("   10  100.0") );
    REQUIRE( Base< MyPair >::read( iss, sink ) );
    REQUIRE( sink.first == 10 );
    REQUIRE( sink.second == 100. );
  }

  struct MyArg{ int value; };

  SECTION( "Vector" ){
    std::vector< int > sink;
    std::vector< int > reference{10, 20, 30};
    MyArg arg{3};
    SECTION( "correct number of entries" ){
      iRecordStream<char> iss( std::istringstream("   10 20 30") );
      REQUIRE( Base< std::vector< int > >::read( iss, sink, arg ) );
      REQUIRE( sink == reference );
    }
    SECTION( "Incorrect number of entries" ){
      iRecordStream<char> iss( std::istringstream("   10 20") );
      REQUIRE( Base< std::vector< int > >::read( iss, sink, arg ) );
      REQUIRE( iss.fail() );
    }
  }

  SECTION( "Vector of doubles" ){
    std::vector< double > sink;
    std::vector< double > reference{10.0, 20.0, 30.0};
    MyArg arg{3};
    SECTION( "correct number of entries" ){
      iRecordStream<char> iss( std::istringstream("   10.0 20.0 30.0") );
      REQUIRE( Base< std::vector< double > >::read( iss, sink, arg ) );
      REQUIRE( sink == reference );
    }
    SECTION( "Incorrect number of entries" ){
      iRecordStream<char> iss( std::istringstream("   10.0 20.0") );
      REQUIRE( Base< std::vector< double > >::read( iss, sink, arg ) );
      REQUIRE( iss.fail() );
    }
  }

  SECTION( "Vector of Quanitities" ){
    std::vector< dimwits::Quantity< dimwits::Meter > > lengths;
    std::vector< dimwits::Quantity< dimwits::Meter > > reflengths
    { 10*dimwits::meter, 20*dimwits::meter, 30*dimwits::meter };

    iRecordStream<char> iss( std::istringstream("   10 20 30") );
    MyArg arg{3};

    REQUIRE( Base< std::vector< dimwits::Quantity< dimwits::Meter > > >::read( 
               iss, lengths, arg ) );
    REQUIRE( lengths == reflengths );
  }
}
