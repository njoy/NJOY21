class Card7{
public:

#include "njoy21/input/POWR/Lib3/Card7/Identb.hpp"

Argument< Identb > identb;

template< typename Istream >
Card7( Istream& is, const int nfis )
try:
  identb( argument::extract< POWR::Lib3::Card7::Identb >( is, nfis ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 7." );
  throw e;
}
};
