class Card4{
public:

#include "njoy21/input/POWR/Lib3/Card4/Mat.hpp"

Argument< Mat > mat;

template< typename Istream >
Card4( Istream& is, const int newmat )
try:
  mat( argument::extract< POWR::Lib3::Card4::Mat >( is, newmat ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 4." );
  throw e;
}
};
