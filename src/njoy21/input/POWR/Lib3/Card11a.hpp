class Card11a{

#include "njoy21/input/POWR/Lib3/Card11a/Tot.hpp"

Tot tot;

template< typename Istream >
Card11a( Istream& e )
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
