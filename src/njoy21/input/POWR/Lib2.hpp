class Lib2 {
public:

#include "njoy21/input/POWR/Lib2/Card3.hpp"
#include "njoy21/input/POWR/Lib2/Card4.hpp"
#include "njoy21/input/POWR/Lib2/Card5.hpp"

#include "njoy21/input/POWR/Lib2/src/readCard45.hpp"

Card3 card3;
optional< std::pair< Card5, Card4 > > card45;

template< typename Istream >
Lib2( Istream& is )
try:
  card3( is ),
  card45( readCard45( is, this->card3.matd.value ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading cards for lib=2." );
  throw e;
}
};
