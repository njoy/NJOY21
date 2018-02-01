class Card1 {
public:

#include "njoy21/input/CCCCR/CBRKXS/Card1/Nti.hpp"
#include "njoy21/input/CCCCR/CBRKXS/Card1/Nzi.hpp"

Argument< Nti > nti;
Argument< Nzi > nzi;

template< typename Istream >
Card1( Istream& is )
try:
  nti( argument::extract< CCCCR::CBRKXS::Card1::Nti >( is ) ),
  nzi( argument::extract< CCCCR::CBRKXS::Card1::Nzi >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card1." );
  throw e;
}
};
