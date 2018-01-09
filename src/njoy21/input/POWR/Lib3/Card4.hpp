class Card4{

#include "njoy21/input/POWR/Lib3/Card4/Mat.hpp"

Mat mat;

template< typename Istream >
Card4( Istream& is )
try:
  mat( argument::extract< POWR::Lib3::Card4::Mat >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 4." );
  throw e;
}
};
