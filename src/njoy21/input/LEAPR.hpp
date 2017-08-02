class LEAPR {
public:
#include "njoy21/input/LEAPR/Card1.hpp"
#include "njoy21/input/LEAPR/Card2.hpp"
#include "njoy21/input/LEAPR/Card3.hpp"
#include "njoy21/input/LEAPR/Card4.hpp"
#include "njoy21/input/LEAPR/Card5.hpp"
#include "njoy21/input/LEAPR/Card6.hpp"
#include "njoy21/input/LEAPR/Card7.hpp"
#include "njoy21/input/LEAPR/Card8.hpp"
#include "njoy21/input/LEAPR/Card9.hpp"
#include "njoy21/input/LEAPR/Card10.hpp"
#include "njoy21/input/LEAPR/Card11.hpp"
#include "njoy21/input/LEAPR/Card12.hpp"
#include "njoy21/input/LEAPR/Card13.hpp"
#include "njoy21/input/LEAPR/Card14.hpp"
#include "njoy21/input/LEAPR/Card15.hpp"
#include "njoy21/input/LEAPR/Card16.hpp"
#include "njoy21/input/LEAPR/Card17.hpp"
#include "njoy21/input/LEAPR/Card18.hpp"
#include "njoy21/input/LEAPR/Card19.hpp"
#include "njoy21/input/LEAPR/Card20.hpp"
using OscillatorTuple = std::tuple< Card15, Card16 >;

using PairCorrelTuple = std::tuple< Card17, Card18, optional< Card19 > >;

using TempSpecificTuple = std::tuple< Card11, Card12, Card13, Card14,
                                 optional<OscillatorTuple>,
                                 optional<PairCorrelTuple> >;

using TempLoopIter = std::tuple< Card10, optional< TempSpecificTuple > >;

using TempLoop = std::vector<TempLoopIter>;

using Card20List = std::vector<Card20>;

Card1 card1;
Card2 card2;
Card3 card3;
Card4 card4;
Card5 card5;
Card6 card6;
Card7 card7;
Card8 card8;
Card9 card9;
TempLoop tempLoop;
Card20List card20List;


static optional<OscillatorTuple> 
buildOscillatorTuple( iRecordStream<char>& is, Card13& card13, Card14& card14 ){

  auto card15 = Card15( is, card14.nd );
  auto card16 = Card16( is, card14.nd, card13.twt, card13.tbeta );
  return OscillatorTuple( card15, card16 );

}

static optional<PairCorrelTuple> 
buildPairCorrelTuple( iRecordStream<char>& is, Card5& card5 ){

  auto card17 = Card17( is );
  auto card18 = Card18( is, card17.nka );
  auto card19 = ( card5.nsk.value == 2 ) ? 
    optional<Card19>( Card19( is ) ) : std::nullopt;
  return PairCorrelTuple( card17, card18, card19 );

}

static optional<TempSpecificTuple>
buildTempSpecificTuple( iRecordStream<char>& is, Card5& card5 ){
  auto card11 = Card11( is );
  auto card12 = Card12( is, card11.ni );
  auto card13 = Card13( is );
  auto card14 = Card14( is );

  // Cards 15 and 16
  auto oscillatorTuple = (card14.nd.value != 0 ) ? 
    buildOscillatorTuple( is, card13, card14 ) : std::nullopt;

  // Cards 17, 18, and 19
  auto pairCorrelTuple = (card5.nsk.value != 0 ) ? 
    buildPairCorrelTuple( is, card5 ) : std::nullopt;
  
  return TempSpecificTuple( card11, card12, card13, card14,
    oscillatorTuple, pairCorrelTuple );
}  


static TempLoopIter buildTempLoopIter( iRecordStream<char>& is, 
                                       Card5& card5, int& i ){

  auto card10 = Card10( is );
  if( i == 0 and card10.temp.value < 0.0 * dimwits::kelvin ){
    Log::info( "A negative card10 temp value indicates that the temperautre\n"
               "specific parameters (cards 11 - 19) will not be provided,\n"
	       "and instead parameters from a previous temperature iteration\n"
	       "will be used.\n"
	       "\n"
	       "Thus, the first temperature loop cannot have a negative\n"
	       "value, since there are no previous loops to reference." );
    throw( "Invalid Card10 temp input" );
  }
  auto tempSpecificTuple = (card10.temp.value > 0.0 * dimwits::kelvin ) ?
    buildTempSpecificTuple( is, card5 ) : std::nullopt;
  return TempLoopIter( card10, tempSpecificTuple );

}


static TempLoop 
buildTempLoop( iRecordStream<char>& is, Card3& card3, Card5& card5 ){

  TempLoop myTempLoop;
  for( int i = 0; i < card3.ntempr.value; i++ ){
    myTempLoop.emplace_back( buildTempLoopIter( is, card5, i ) );
  }
   
  return myTempLoop;
  
} 
  

template <typename Char> 
  LEAPR( iRecordStream<Char>& iss )
  try:
    card1( iss ),
    card2( iss ),
    card3( iss ),
    card4( iss ),
    card5( iss ),
    card6( iss ),
    card7( iss ),
    card8( iss, this->card7.nalpha ),
    card9( iss, this->card7.nbeta  ),
    tempLoop( buildTempLoop( iss, this->card3, this->card5 ) )
    {
      do {
        card20List.emplace_back( iss );
      }
      while( card20List.back().comment.value );
      card20List.pop_back();
      if( card20List.size() == 0 ){
        Log::info( "Failed reading card20" );
        throw( "invalid card20 input" );
      }

    }

  catch( std::exception &e ){
    Log::info( "Trouble with validating LEAPR input" );
    throw e;
  }
};
