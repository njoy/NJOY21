class Card2 {
public:

using Nin = argument::common::Nin;
#include "njoy21/input/ERRORR/DummyMF33/Card2/Nout.hpp"

Argument< Nin > nin;
Argument< Nout > nout;

template< typename Istream >
Card2( Istream& is )
try:
  nin( argument::extract< ERRORR::DummyMF33::Card2::Nin >( is ) ),
  nout( argument::extract< ERRORR::DummyMF33::Card2::Nout >( is,
                                                             this->nin.value ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card2." );
  throw e;
}
};
