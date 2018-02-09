class Card3 {
public:

#include "njoy21/input/CCCCR/Card3/Hsetid.hpp"

Argument< Hsetid > hsetid;

template< typename Istream >
Card3( Istream& is )
try:
  hsetid( argument::extract< CCCCR::Card3::Hsetid >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card3." );
  throw e;
}
};
