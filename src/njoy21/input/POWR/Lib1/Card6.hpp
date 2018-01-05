class Card6{

#include "njoy21/input/POWR/Lib1/Card6/Abs.hpp"

Abs abs;

template< typename Istream >
Card6( Istream& is )
try:
  abs( argument::extract< POWR::Lib1::Card6::Abs >( is, 69 ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card6." );
  throw e;
}
};
