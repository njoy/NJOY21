class GROUPR {
public:
  /* nested types */
  #include "njoy21/input/GROUPR/Card1.hpp"
  #include "njoy21/input/GROUPR/Card2.hpp"
  #include "njoy21/input/GROUPR/Card3.hpp"
  #include "njoy21/input/GROUPR/Card4.hpp"
  #include "njoy21/input/GROUPR/Card5.hpp"

  Card1 card1;
  Card2 card2;
  Card3 card3;
  Card4 card4;
  Card5 card5;

  template< typename Istream >
  GROUPR( Istream& is )
  try:
    card1( is ),
    card2( is ),
    card3( is ),
    card4( is ),
    card5( is )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating GROUPR input." );
    throw e;
  }
};
