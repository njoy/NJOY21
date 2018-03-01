class Card13b {
public:

#include "njoy21/input/ERRORR/Normal/Card13b/Eb.hpp"
#include "njoy21/input/ERRORR/Normal/Card13b/Tb.hpp"
#include "njoy21/input/ERRORR/Normal/Card13b/Ec.hpp"
#include "njoy21/input/ERRORR/Normal/Card13b/Tc.hpp"

Argument< Eb > eb;
Argument< Tb > tb;
Argument< Ec > ec;
Argument< Tc > tc;

template< typename Istream >
Card13b( Istream& is )
try:
  eb( argument::extract< ERRORR::Normal::Card13b::Eb >( is ) ),
  tb( argument::extract< ERRORR::Normal::Card13b::Tb >( is ) ),
  ec( argument::extract< ERRORR::Normal::Card13b::Ec >( is ) ),
  tc( argument::extract< ERRORR::Normal::Card13b::Tc >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card13b." );
  throw e;
}
};
