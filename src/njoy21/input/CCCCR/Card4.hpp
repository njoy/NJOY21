class Card4 {
public:

#include "njoy21/input/CCCCR/Card4/Ngroup.hpp"
#include "njoy21/input/CCCCR/Card4/Nggrup.hpp"
#include "njoy21/input/CCCCR/Card4/Niso.hpp"
#include "njoy21/input/CCCCR/Card4/Maxord.hpp"
#include "njoy21/input/CCCCR/Card4/Ifopt.hpp"

Argument< Ngroup > ngroup;
Argument< Nggrup > nggrup;
Argument< Niso > niso;
Argument< Maxord > maxord;
Argument< Ifopt > ifopt;

template< typename Istream >
Card4( Istream& is )
try:
  ngroup( argument::extract< CCCCR::Card4::Ngroup >( is ) ),
  nggrup( argument::extract< CCCCR::Card4::Nggrup >( is ) ),
  niso( argument::extract< CCCCR::Card4::Niso >( is ) ),
  maxord( argument::extract< CCCCR::Card4::Maxord >( is ) ),
  ifopt( argument::extract< CCCCR::Card4::Ifopt >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card4." );
  throw e;
}
};
