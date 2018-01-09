class Card4{

#include "njoy21/input/POWR/Lib2/Card4/Itrc.hpp"
#include "njoy21/input/POWR/Lib2/Card4/Mti.hpp"
#include "njoy21/input/POWR/Lib2/Card4/Mtc.hpp"

Itrc itrc;
Mti mti;
Mtc mtc;

template< typename Istream >
Card4( Istream& is )
try:
  itrc( argument::extract< POWR::Lib2::Card4::Itrc >( is ) ),
  mti( argument::extract< POWR::Lib2::Card4::Mti >( is ) ),
  mtc( argument::extract< POWR::Lib2::Card4::Mtc >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 4." );
  throw e;
}
};
