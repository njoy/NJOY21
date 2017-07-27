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

Card1 card1;
Card2 card2;
Card3 card3;
Card4 card4;
Card5 card5;
Card6 card6;
Card7 card7;
Card8 card8;
Card9 card9;
Card10 card10;

template <typename Char> 
  LEAPR( iRecordStream<Char>& iss )
  try:
    card1( iss ){}
  catch( std::exception &e ){
    Log::info( "Trouble with validating LEAPR input" );
    throw e;
  }
};
