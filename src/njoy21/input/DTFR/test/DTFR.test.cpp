#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

bool isControlTuple( const DTFR::ControlTuple& ){
  return true;
}
template< typename T >
bool isControlTuple( const T& ){
  return false;
}

void correctCard3Read( const DTFR::ControlTuple& ct,
  const int& nlmax, const int& ng, const int& iptotl, const int& ipingp,
  const int& itabl, const int& ned, const int& ntherm ){
  const auto& card3 = std::get<0>(ct);
  REQUIRE( card3.nlmax.value == nlmax );
  REQUIRE( card3.ng.value == ng );
  REQUIRE( card3.iptotl.value == iptotl );
  REQUIRE( card3.ipingp.value == ipingp );
  REQUIRE( card3.itabl.value == itabl );
  REQUIRE( card3.ned.value == ned );
  REQUIRE( card3.ntherm.value == ntherm );

}
template< typename... Args >
void correctCard3Read( const Args&... ){
  REQUIRE( false );
}

void card3aExists( const DTFR::ControlTuple& ct, bool shouldBeThere ){
  const auto& card3a = std::get<1>(ct);
  if ( shouldBeThere ){ REQUIRE( card3a ); }
  else { REQUIRE( ! card3a ); }
}
template< typename... Args >
void card3aExists( const Args&... ){
  REQUIRE( false );
}

void correctCard3aRead( const DTFR::ControlTuple& ct,
  int mti, int mtc, int nlc ){
  const auto& card3a = std::get<1>(ct);
  REQUIRE( card3a->mti.value == mti );
  REQUIRE( card3a->mtc.value == mtc );
  REQUIRE( card3a->nlc.value == nlc );
}
template< typename... Args >
void correctCard3aRead( const Args&... ){
  REQUIRE( false );
}

template< typename str > 
void correctCard4Read( const DTFR::ControlTuple& ct, 
  const str hollerithNames ){
  const auto& card4 = std::get<2>(ct);
  for ( unsigned i = 0; i < card4.hollerithNames.value.size(); i++ ){
    REQUIRE( card4.hollerithNames.value[i] == hollerithNames[i] );
  }
}
template< typename... Args >
void correctCard4Read( const Args&... ){
  REQUIRE( false );
}

template< typename vec >
void correctCard5Read( const DTFR::ControlTuple& ct,
  vec& correctCard5Vals ){
  const auto& card5List = std::get<3>(ct);
  REQUIRE( card5List.size() == correctCard5Vals.size() );
  for ( unsigned i = 0; i < card5List.size(); i++ ){
    REQUIRE( card5List[i].jpos.value == correctCard5Vals[i][0] );
    REQUIRE( card5List[i].mt.value   == correctCard5Vals[i][1] );
    REQUIRE( card5List[i].mult.value == correctCard5Vals[i][2] );
  }
}
template< typename... Args >
void correctCard5Read( const Args&... ){
  REQUIRE( false );
}

void correctCard6Read( const DTFR::Card6& card6,
  int nlmax, int ng ){
  REQUIRE( card6.nlmax.value == nlmax );
  REQUIRE( card6.ng.value    == ng );
}

template< typename... Args >
void correctCard6Read( const Args&...){
  REQUIRE( false );
}


SCENARIO( "DTFR input, [DTFR]" ){
  GIVEN( "a card2 iedit value of 0 and card3 ntherm value of 0" ){
    WHEN( "all entries are valid" ){
      iRecordStream<char> iss( std::istringstream( 
        "33 35 31 36\n"
        "1 1 0\n"
        "5 12 4 5 16 1 0\n"
        "pheat\n"
        "1 621 1\n"
        " /\n"
	"hisnam /\n"
        "/"
        ) );

      DTFR dtfr( iss );
      THEN( "Card1 and Card2 should have correct inputs" ){
        REQUIRE( dtfr.card1.nin.value   == 33 );
        REQUIRE( dtfr.card1.nout.value  == 35 );
        REQUIRE( dtfr.card1.npend.value == 31 );
        REQUIRE( dtfr.card1.nplot.value == 36 );

        REQUIRE( dtfr.card2.iprint.value ==  1 );
        REQUIRE( dtfr.card2.ifilm.value  ==  1 );
        REQUIRE( dtfr.card2.iedit.value  ==  0 );

      } // THEN
  
      THEN( "Card3 and Card4 should exist with correct inputs" ){
        REQUIRE( std::visit( []( const auto& value ){ 
          return isControlTuple( value ); }, dtfr.controlVariant ) );
	
        std::visit( []( const auto& value ) { return 
          correctCard3Read( value, 5,12,4,5,16,1,0 ); }, dtfr.controlVariant ); 

	std::visit( []( const auto& value ) { return 
          card3aExists( value, false ); }, dtfr.controlVariant ); 

	std::vector<std::string> correctHolNames = {"pheat"};
        std::visit( [correctHolNames]( const auto& value) { return
          correctCard4Read( value, correctHolNames ); }, dtfr.controlVariant );
	
        std::vector<std::vector<int>> correctCard5 = {{1,621,1}};
        std::visit( [correctCard5]( const auto& value ) { return
          correctCard5Read( value, correctCard5 ); }, dtfr.controlVariant );
      
      } // THEN
      
      THEN( "Card7 and Card8 should exist with correct inputs" ){
        REQUIRE( dtfr.card7.nptabl.value == 0 );
        REQUIRE( dtfr.card7.ngp.value == 0 );
        
        REQUIRE( dtfr.card8List.size() == 1 );
        REQUIRE( dtfr.card8List[0].hisnam.value == std::string("hisnam") );
        REQUIRE( dtfr.card8List[0].mat.value    == 0 );
        REQUIRE( dtfr.card8List[0].jsigz.value  == 1 );
        REQUIRE( dtfr.card8List[0].dtemp.value  == 300*dimwits::kelvin );
      } // THEN

    } // WHEN

    WHEN( "not all entries are valid" ){
      iRecordStream<char> iss( std::istringstream( 
        "33 35 31 36\n"
        "1 1 0\n"
        "5 12 4 5 16 1 0\n"
        "pheatlong\n"
        "1 621 1\n"
        "/\n"
        "hisname /\n"
	"/"
	
        ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( DTFR ( iss ) );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "a card2 iedit value of 0 and card3 ntherm value of 1" ){
    WHEN( "all entries are valid" ){
      iRecordStream<char> iss( std::istringstream( 
        "33 35 31 36\n"
        "1 1 0\n"
        "5 12 4 5 16 1 1\n"
	"221 0 0\n"
        "pheat\n"
        "1 621 1\n"
        " /\n"
	"hisnam /\n"
        "/"
        ) );
      DTFR dtfr( iss );
      THEN( "card3a should exist" ){
        std::visit( []( const auto& value ){ return 
          card3aExists( value, true ); }, dtfr.controlVariant );
	std::visit( []( const auto& value ) { return 
          correctCard3aRead( value, 221, 0, 0 ); }, dtfr.controlVariant ); 

      } // THEN
    } // WHEN
  } // GIVEN    

  GIVEN( "a card2 iedit value of 1" ){
    WHEN( "all entries are valid" ){
      iRecordStream<char> iss( std::istringstream( 
        "33 35 31 36\n"
        "1 1 1\n"
        "5 30\n"
        "0 0\n"
        "hisnam 125 1 300\n"
        "hernam 9228 1 450\n"
        "/"
        ) );

      DTFR dtfr( iss );
      THEN( "Card1 and Card2 should have correct inputs" ){
        REQUIRE( dtfr.card1.nin.value   == 33 );
        REQUIRE( dtfr.card1.nout.value  == 35 );
        REQUIRE( dtfr.card1.npend.value == 31 );
        REQUIRE( dtfr.card1.nplot.value == 36 );

        REQUIRE( dtfr.card2.iprint.value ==  1 );
        REQUIRE( dtfr.card2.ifilm.value  ==  1 );
        REQUIRE( dtfr.card2.iedit.value  ==  1 );

      } // THEN

      THEN( "Card6 exists with correct values" ){ 
        std::visit( []( const auto& value ){ return
          correctCard6Read( value, 5, 30 ); }, dtfr.controlVariant );
      } // THEN
      THEN( "Card7 and Card8 have the appropriate inputs" ){
        REQUIRE( dtfr.card7.nptabl.value == 0 );
        REQUIRE( dtfr.card7.ngp.value    == 0 );
       
        REQUIRE( dtfr.card8List.size() == 2 );
        REQUIRE( dtfr.card8List[0].hisnam.value == std::string("hisnam") );
        REQUIRE( dtfr.card8List[0].mat.value    == 125 );
        REQUIRE( dtfr.card8List[0].jsigz.value  == 1 );
        REQUIRE( dtfr.card8List[0].dtemp.value  == 300*dimwits::kelvin );

	REQUIRE( dtfr.card8List[1].hisnam.value == std::string("hernam") );
        REQUIRE( dtfr.card8List[1].mat.value    == 9228 );
        REQUIRE( dtfr.card8List[1].jsigz.value  == 1 );
        REQUIRE( dtfr.card8List[1].dtemp.value  == 450*dimwits::kelvin );


      } // THEN

    } // WHEN
    WHEN( "not all entries are valid" ){
      iRecordStream<char> iss( std::istringstream( 
        "33 35 31 36\n"
        "1 1 1\n"
        "5 30\n"
        "0 0\n"
        "hisnam 125 1 -300\n"
        "/"
        ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( DTFR ( iss ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
