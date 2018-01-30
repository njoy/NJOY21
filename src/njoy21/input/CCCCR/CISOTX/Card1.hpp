class Card1 {
public:

#include "njoy21/input/CCCCR/CISOTX/Card1/Nsblok.hpp"
#include "njoy21/input/CCCCR/CISOTX/Card1/Maxup.hpp"
#include "njoy21/input/CCCCR/CISOTX/Card1/Maxdn.hpp"
#include "njoy21/input/CCCCR/CISOTX/Card1/Ichix.hpp"

Argument< Nsblok > nsblok;
Argument< Maxup > maxup;
Argument< Maxdn > maxdn;
Argument< Ichix > ichix;

template< typename Istream >
Card1( Istream& is, const int ngroup )
try:
  nsblok( argument::extract< CCCCR::CISOTX::Card1::Nsblok >( is, ngroup ) ),
  maxup( argument::extract< CCCCR::CISOTX::Card1::Maxup >( is ) ),
  maxdn( argument::extract< CCCCR::CISOTX::Card1::Maxdn >( is, ngroup ) ),
  ichix( argument::extract< CCCCR::CISOTX::Card1::Ichix >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card1." );
  throw e;
}
};
