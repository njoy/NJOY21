class Card12a {
public:

#include "njoy21/input/ERRORR/Normal/Card12a/Ngn.hpp"

Argument< Ngn > ngn;

template< typename Istream >
Card12a( Istream& is )
try:
  ngn( argument::extract< ERRORR::Normal::Card12a::Ngn >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card12a." );
  throw e;
}
};
