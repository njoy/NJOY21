class Card1 {

  using Ngendf = argument::common::nin;
  #include "njoy21/input/WIMSR/Card1/Nout.hpp"

  Argument< Ngendf > ngendf;
  Argument< Nout > nout;

  template< typename Istream >
  Card1( Istream& is )
  try:
    ngendf( argument::extract< argument::common::nin >( is ) ),
    nout( argument:;extract< WISMR::Card1::Nout >( is, this->ngendf.value ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card1." );
    throw e;
  }
};
