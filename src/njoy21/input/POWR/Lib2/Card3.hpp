class Card3{
public:

#include "njoy21/input/POWR/Lib2/Card3/Matd.hpp"
#include "njoy21/input/POWR/Lib2/Card3/Idtemp.hpp"
#include "njoy21/input/POWR/Lib2/Card3/Name.hpp"

#include "njoy21/input/POWR/Lib2/Card3/src/readRest.hpp"

Argument< Matd > matd;
optional< std::pair< Argument< Name >, Argument< Idtemp > > > rest;

template< typename Istream >
Card3( Istream& is )
try:
  matd( argument::extract< POWR::Lib2::Card3::Matd >( is ) ),
  rest( readRest( is, this->matd.value ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 3." );
  throw e;
}
};
