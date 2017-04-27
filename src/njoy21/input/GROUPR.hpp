class GROUPR {
public:
  /* nested types */
  #include "njoy21/input/GROUPR/Card1.hpp"
  #include "njoy21/input/GROUPR/Card2.hpp"
  #include "njoy21/input/GROUPR/Card3.hpp"
  #include "njoy21/input/GROUPR/Card4.hpp"
  #include "njoy21/input/GROUPR/Card5.hpp"
  #include "njoy21/input/GROUPR/Card6a.hpp"
  #include "njoy21/input/GROUPR/Card6b.hpp"
  #include "njoy21/input/GROUPR/Card7a.hpp"
  #include "njoy21/input/GROUPR/Card7b.hpp"
  #include "njoy21/input/GROUPR/Card8a.hpp"
//#include "njoy21/input/GROUPR/Card8b.hpp"
  #include "njoy21/input/GROUPR/Card8c.hpp"
  #include "njoy21/input/GROUPR/Card8d.hpp"
  #include "njoy21/input/GROUPR/Card9.hpp"
  #include "njoy21/input/GROUPR/Card10.hpp"

  Card1 card1;
  Card2 card2;
  Card3 card3;
  Card4 card4;
  Card5 card5;
  Card6a card6a;
  Card6b card6b;
  Card7a card7a;
  Card7b card7b;
  Card8a card8a;
//Card8b card8b;
  Card8c card8c;
  Card8d card8d;
  Card9 card9;
  Card10 card10;

  template< typename Istream >
  GROUPR( Istream& is )
  try:
    card1( is ),
    card2( is ),
    card3( is ),
    card4( is ),
    card5( is ),
    card6a( is ),
    card6b( is ),
    card7a( is ),
    card7b( is ),
    card8a( is ),
//  card8b( is ),
//  card8c( is ),
    card8d( is ),
    card9( is ),
    card10( is )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating GROUPR input." );
    throw e;
  }
};
