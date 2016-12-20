#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

std::string card1(" 21 22\n");
std::string card2("'This is a sample Card2'\n");
std::string card3(" 1306 3 0\n");
std::string card4(" 0.005 0 0.1 5e-07\n");
std::string card5( "'This a sample description TEXT Record for Card5'\n" );
auto card5String = std::string( ++(card5.begin()), (card5.end() - 2) ); 
std::string card6(" 1.0 2 3.0\n");

SCENARIO( "Parsing valid RECONR input" ){
  WHEN( "Cards 3,4,3" ){
    iRecordStream<char> iss
      ( std::istringstream( card1 + card2 + " 1306 0 0\n" + card4 + "0/\n" ) );

    THEN( "The read values can be verified" ){
      RECONR reconr(iss);
      REQUIRE( 21 == reconr.card1.nendf.value );

      REQUIRE( 1 == reconr.cardSequence.size() );

      auto& card3 = std::get<0>( reconr.cardSequence.front() );
      REQUIRE( 1306 == card3.mat.value );
      REQUIRE( 0 == card3.ncards.value );
      REQUIRE( 0 == card3.ngrid.value );

      auto& card4 = std::get<1>( reconr.cardSequence.front() );
      REQUIRE( 0.005 == card4.err.value );
      REQUIRE( 0.0*dimwits::kelvin == card4.tempr.value );
      REQUIRE( 0.1 == card4.errmax.value );
      REQUIRE( 5E-7*dimwits::barn == card4.errint.value );

      auto& card5 = std::get<2>( reconr.cardSequence.front() );
      REQUIRE( not card5 );

      auto& card6 = std::get<3>( reconr.cardSequence.front() );
      REQUIRE( not card6 );

      REQUIRE( 5 == iss.lineNumber );
    }
  }
  WHEN( "Cards 3,4,5,3" ){
    iRecordStream<char> iss
      ( std::istringstream( card1 + card2 + " 1306 1 0\n"
  			    + card4 + card5 + "0/\n" ) );

    THEN( "The read values can be verified" ){
      RECONR reconr(iss);

      auto& card5 = std::get<2>( reconr.cardSequence.front() );
      REQUIRE( card5 );
      REQUIRE( 1 == card5->size() );
      REQUIRE( card5String == card5->front().cards.value );

      auto& card6 = std::get<3>( reconr.cardSequence.front() );
      REQUIRE( not card6 );
    }
  }

  WHEN( "Cards 3,4,5,6,3" ){
    iRecordStream<char> iss
      ( std::istringstream( card1 + card2 + " 1306 1 3\n"
  			    + card4 + card5 + card6 + "0/\n" ) );

    THEN( "The read values can be verified" ){
      RECONR reconr(iss);

      auto& card5 = std::get<2>( reconr.cardSequence.front() );
      REQUIRE( card5 );
      REQUIRE( 1 == card5->size() );

      auto& card6 = std::get<3>( reconr.cardSequence.front() );
      REQUIRE( card6 );
      REQUIRE( 3 == card6->enode.value.size() );
      REQUIRE( 1.0*dimwits::electronVolt == card6->enode.value[0] );
      REQUIRE( 2.0*dimwits::electronVolt == card6->enode.value[1] );
      REQUIRE( 3.0*dimwits::electronVolt == card6->enode.value[2] );
    }
  }
  WHEN( "Cards 3,4,6,3" ){
    iRecordStream<char> iss
      ( std::istringstream( card1 + card2 + " 1306 0 3\n"
  			    + card4 + card6 + "0/\n" ) );

    THEN( "The read values can be verified" ){
      RECONR reconr(iss);

      auto& card5 = std::get<2>( reconr.cardSequence.front() );
      REQUIRE( not card5 );

      auto& card6 = std::get<3>( reconr.cardSequence.front() );
      REQUIRE( card6 );
      REQUIRE( 3 == card6->enode.value.size() );
      REQUIRE( 1.0*dimwits::electronVolt == card6->enode.value[0] );
      REQUIRE( 2.0*dimwits::electronVolt == card6->enode.value[1] );
      REQUIRE( 3.0*dimwits::electronVolt == card6->enode.value[2] );
    }
  }
  WHEN( "Cards 3,4,5,5,5,3" ){
    iRecordStream<char> iss
      ( std::istringstream( card1 + card2 + " 1306 3 0\n"
  			    + card4 + card5 + card5 + card5 + "0/\n" ) );

    THEN( "The read values can be verified" ){
      RECONR reconr(iss);

      auto& card5 = std::get<2>( reconr.cardSequence.front() );
      REQUIRE( card5 );
      REQUIRE( 3 == card5->size() );
      REQUIRE( card5String == card5->at(0).cards.value );
      REQUIRE( card5String == card5->at(1).cards.value );
      REQUIRE( card5String == card5->at(2).cards.value );

      auto& card6 = std::get<3>( reconr.cardSequence.front() );
      REQUIRE( not card6 );
    }
  }
  WHEN( "Cards 3,4,5,6,3,4,3" ){
    iRecordStream<char> iss
      ( std::istringstream( card1 + card2 + " 1306 1 3\n" + card4 + card5
  			    + card6 + " 1306 0 0\n" + card4 + "0/\n" ) );

    THEN( "The read values can be verified" ){
      RECONR reconr(iss);

      REQUIRE( 2 == reconr.cardSequence.size() );

      auto& card3 = std::get<0>( reconr.cardSequence.front() );
      REQUIRE( 1306 == card3.mat.value );
      REQUIRE( 1 == card3.ncards.value );
      REQUIRE( 3 == card3.ngrid.value );
      card3 = std::get<0>( reconr.cardSequence.back() );
      REQUIRE( 1306 == card3.mat.value );
      REQUIRE( 0 == card3.ncards.value );
      REQUIRE( 0 == card3.ngrid.value );

      auto& card5 = std::get<2>( reconr.cardSequence.front() );
      REQUIRE( card5 );
      REQUIRE( card5String == card5->front().cards.value );

      auto& card6 = std::get<3>( reconr.cardSequence.front() );
      REQUIRE( card6 );
      REQUIRE( 3 == card6->enode.value.size() );
      REQUIRE( 1.0*dimwits::electronVolt == card6->enode.value[0] );
      REQUIRE( 2.0*dimwits::electronVolt == card6->enode.value[1] );
      REQUIRE( 3.0*dimwits::electronVolt == card6->enode.value[2] );
    }
  }
} // SCENARIO

SCENARIO( "Parsing invalid RECONR input" ){
  std::istringstream iss;

  WHEN( "Only terminating Card3" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss
	( std::istringstream( card1 + card2 + "0/\n" ) );

      REQUIRE_THROWS( RECONR reconr(iss) );
    }
  }
  WHEN( "Cards non-terminating-3" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss
	( std::istringstream( card1 + card2 + card3 ) );
      REQUIRE_THROWS( RECONR reconr(iss) );
    }
  }
  WHEN( "Cards 3,4" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss
	( std::istringstream( card1 + card2 + " 1234 0 0\n"  + card4 ) );
      REQUIRE_THROWS( RECONR reconr(iss) );
    }
  }
  WHEN( "Cards 3,4,5,5,5,3 and ncards = 2" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss
	( std::istringstream( card1 + card2 + "1306 2 0\n" + card4 + card5
			      + card5 + card5 + "0/\n" ) );
      REQUIRE_THROWS( RECONR reconr(iss) );
    }
  }
  WHEN( "Cards 3,4,5,5,5,3 and ncards = 4" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss
	( std::istringstream( card1 + card2 + "1306 4 0\n" + card4
			      + card5 + card5 + card5 + "0/\n" ) );
      REQUIRE_THROWS( RECONR reconr(iss) );
    }
  }
  WHEN( "Cards 3,4,6,3 and ngrid = 0" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss
	( std::istringstream( card1 + card2 + "1306 0 0\n"
			      + card4 + card6 + "0/\n" ) );
      REQUIRE_THROWS( RECONR reconr(iss) );
    }
  }
  WHEN( "Cards 3,4,3 and ngrid > 0" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss
	( std::istringstream( card1 + card2 + "1306 0 1000000\n"
			      + card4 + "0/\n" ) );
      REQUIRE_THROWS( RECONR reconr(iss) );
    }
  }
  WHEN( "Cards 3,4, and faulty 5" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss
	( std::istringstream( card1 + card2 + "1306 1 0\n"
			      + card4 + "'abcd\n" + "0/\n" ) );
      REQUIRE_THROWS( RECONR reconr(iss) );
    }
  }
}
