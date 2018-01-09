class Lib2 {

#include "njoy21/input/POWR/Lib2/Card3.hpp"
#include "njoy21/input/POWR/Lib2/Card4.hpp"
#include "njoy21/input/POWR/Lib2/Card5.hpp"

Card3 card3;
Card4 card4;
Card5 card5;

template< typename Istream >
Lib2( Istream& is )
try:
  card3( is ),
  card4( is ),
  card5( is )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading cards for lib=2." );
  throw e;
}
};
