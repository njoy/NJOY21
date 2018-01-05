class Card2{

#include "njoy21/input/POWR/Card2/Lib.hpp"
#include "njoy21/input/POWR/Card2/Iprint.hpp"
#include "njoy21/input/POWR/Card2/Iclaps.hpp"

Lib lib;
Iprint iprint;
Iclaps iclaps;

template< typename Istream >
Card2( Istream& is )
try:
  lib( is ),
  iprint( is ),
  iclaps( is )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card2." );
  throw e;
}
};
