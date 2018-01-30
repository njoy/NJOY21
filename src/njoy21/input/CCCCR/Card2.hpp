class Card2 {
public:

#include "njoy21/input/CCCCR/Card2/Lprint.hpp"
#include "njoy21/input/CCCCR/Card2/Ivers.hpp"
#include "njoy21/input/CCCCR/Card2/Huse.hpp"

Argument< Lprint > lprint;
Argument< Ivers > ivers;
Argument< Huse > huse;

template< typename Istream >
Card2( Istream& is )
try:
  lprint( argument::extract< CCCCR::Card2::Lprint >( is ) ),
  ivers( argument::extract< CCCCR::Card2::Ivers >( is ) ),
  huse( argument::extract< CCCCR::Card2::Huse >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card2." );
  throw e;
}
};
