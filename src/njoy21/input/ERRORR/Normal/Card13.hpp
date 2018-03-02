class Card13 {
public:

#include "njoy21/input/ERRORR/Normal/Card13/Wght.hpp"

Argument< Wght > wght;

template< typename Istream >
Card13( Istream& is )
try:
  wght( argument::extract< ERRORR::Normal::Card13::Wght >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card13." );
  throw e;
}
};
