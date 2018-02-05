class Card1 {
public:

#include "njoy21/input/MIXR/Card1/Nout.hpp"
using Nin = argument::common::Nin;

#include "njoy21/input/MIXR/Card1/src/readNin.hpp"

Argument< Nout > nout;
Argument< Nin > nin;

template< typename Char >
Card1( iRecordStream< Char >& is )
  try:
    nout( argument::extract< MIXR::Card1::Nout >( is ) ),
    nin( readNin( is, this->nout.value ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card1." );
    throw e;
  }
};
