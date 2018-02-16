class Card9 {
public:

#include "njoy21/input/ERRORR/Rest/Card9/Akxy.hpp"

Argument< Akxy > akxy;

template< typename Istream >
Card9( Istream& is, const int nmt, const int diag )
try:
  akxy( argument::extract< ERRORR::Rest::Card9::Akxy >( is, nmt, diag ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card9." );
  throw e;
}
};
