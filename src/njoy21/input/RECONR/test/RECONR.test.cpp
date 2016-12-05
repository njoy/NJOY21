#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

std::string sCard1(" 21 22\n");
std::string sCard2("This is a sample Card2\n");
std::string sCard12 = sCard1 + sCard2;

std::string sCard3(" 1306 3 0\n");
std::string sCard3_0("0/\n");
std::string sCard4(" 0.005 0 0.1 5e-07\n");
std::string qCard5( "This a sample description TEXT Record for Card5" );
std::string sCard5( "'" + qCard5 + "'\n" );
std::string sCard6_3(" 1.0 2 3.0\n");

SCENARIO( "Parsing valid RECONR input" ){
  std::istringstream iss;
  long ln(0);
  WHEN( "Cards 3,4,3" ){
    iss.str( sCard12 + " 1306 0 0\n" + sCard4 + sCard3_0 );

    THEN( "The read values can be verified" ){
      RECONR reconr(iss,ln);
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

      REQUIRE( 5 == ln );
    }
  }
  WHEN( "Cards 3,4,5,3" ){
    iss.str( sCard12 + " 1306 1 0\n" + sCard4 + sCard5 + sCard3_0 );

    THEN( "The read values can be verified" ){
      RECONR reconr(iss,ln);

      auto& card5 = std::get<2>( reconr.cardSequence.front() );
      REQUIRE( card5 );
      REQUIRE( 1 == card5->size() );
      REQUIRE( qCard5 == card5->front().cards.value );

      auto& card6 = std::get<3>( reconr.cardSequence.front() );
      REQUIRE( not card6 );
    }
  }
  WHEN( "Cards 3,4,5,6,3" ){
    iss.str( sCard12 + " 1306 1 3\n" + sCard4 + sCard5 + sCard6_3 + sCard3_0 );

    THEN( "The read values can be verified" ){
      RECONR reconr(iss,ln);

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
    iss.str( sCard12 + " 1306 0 3\n" + sCard4 + sCard6_3 + sCard3_0 );

    THEN( "The read values can be verified" ){
      RECONR reconr(iss,ln);

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
    iss.str( sCard12 + " 1306 3 0\n" + sCard4 + sCard5 + sCard5 + sCard5 + 
            sCard3_0 );

    THEN( "The read values can be verified" ){
      RECONR reconr(iss,ln);

      auto& card5 = std::get<2>( reconr.cardSequence.front() );
      REQUIRE( card5 );
      REQUIRE( 3 == card5->size() );
      REQUIRE( qCard5 == card5->at(0).cards.value );
      REQUIRE( qCard5 == card5->at(1).cards.value );
      REQUIRE( qCard5 == card5->at(2).cards.value );

      auto& card6 = std::get<3>( reconr.cardSequence.front() );
      REQUIRE( not card6 );
    }
  }
  WHEN( "Cards 3,4,5,6,3,4,3" ){
    iss.str( sCard12 + " 1306 1 3\n" + sCard4 + sCard5 + sCard6_3 + 
            " 1306 0 0\n" + sCard4 + sCard3_0 );

    THEN( "The read values can be verified" ){
      RECONR reconr(iss,ln);

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
      REQUIRE( qCard5 == card5->front().cards.value );

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
  long ln(0);

  WHEN( "Only terminating Card3" ){
    THEN( "an exception is thrown" ){
      njoy::Log::info(
          "\nTesting failure when only have cards 1,2,3(terminating).\n");
      iss.str( sCard12 + sCard3_0 );

      REQUIRE_THROWS( RECONR(iss, ln) );
    }
  }
  WHEN( "Cards non-terminating-3" ){
    THEN( "an exception is thrown" ){
      njoy::Log::info(
          "\nTesting failure when only have cards 1,2,3(non-terminating).\n");
      iss.str( sCard12 + sCard3 );

      REQUIRE_THROWS( RECONR(iss, ln) );
    }
  }
  WHEN( "Cards 3,4" ){
    THEN( "an exception is thrown" ){
      njoy::Log::info("\nTesting failure with no terminating Card3.\n");
      iss.str( sCard12 + " 1234 0 0\n"  + sCard4 );

      REQUIRE_THROWS( RECONR(iss, ln) );
    }
  }
  WHEN( "Cards 3,4,5,5,5,3 and ncards = 2" ){
    THEN( "an exception is thrown" ){
      njoy::Log::info("\nTesting failure when # of Card5s > ncards.\n");
      iss.str( sCard12 + "1306 2 0\n" + sCard4 + 
               sCard5 + sCard5 + sCard5 + sCard3_0 );

      REQUIRE_THROWS( RECONR(iss, ln) );
    }
  }
  WHEN( "Cards 3,4,5,5,5,3 and ncards = 4" ){
    THEN( "an exception is thrown" ){
      njoy::Log::info("\nTesting failure when # of Card5s < ncards.\n");
      iss.str( sCard12 + "1306 4 0\n" + sCard4 + sCard5 + sCard5 + sCard5 + 
               sCard3_0 );

      REQUIRE_THROWS( RECONR(iss, ln) );
    }
  }
  WHEN( "Cards 3,4,6,3 and ngrid = 0" ){
    THEN( "an exception is thrown" ){
      njoy::Log::info(
          "\nTesting failure when ngrid = 0 and there is a Card 6.\n");
      iss.str( sCard12 + "1306 0 0\n"  + sCard4 + sCard6_3 + sCard3_0 );

      REQUIRE_THROWS( RECONR(iss, ln) );
    }
  }
  WHEN( "Cards 3,4,3 and ngrid > 0" ){
    THEN( "an exception is thrown" ){
      njoy::Log::info(
          "\nTesting failure when ngrid > 0 and there is no Card 6.\n");
      iss.str( sCard12 + "1306 0 1000000\n"  + sCard4 + sCard3_0 );

      REQUIRE_THROWS( RECONR(iss, ln) );
    }
  }
  WHEN( "Cards 3,4, and faulty 5" ){
    THEN( "an exception is thrown" ){
      njoy::Log::info(
          "\nTesting failure when ngrid > 0 and there is no Card 6.\n");
      iss.str( sCard12 + "1306 1 0\n"  + sCard4 + "'abcd\n" + sCard3_0 );

      REQUIRE_THROWS( RECONR(iss, ln) );
    }
  }
}
