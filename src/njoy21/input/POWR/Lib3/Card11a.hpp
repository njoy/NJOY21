class Card11a{
public:

#include "njoy21/input/POWR/Lib3/Card11a/Tot.hpp"

Argument< Tot > tot;

template< typename Istream >
Card11a( Istream& is )
try:
  tot( argument::extract< POWR::Lib3::Card11a::Tot >( is, 69 ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 11a." );
  throw e;
}
};
