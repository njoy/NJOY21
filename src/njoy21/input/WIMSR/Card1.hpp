class Card1 {
public:

  using Ngendf = argument::common::Nin;
  #include "njoy21/input/WIMSR/Card1/Nout.hpp"

  Argument< Ngendf > ngendf;
  Argument< Nout > nout;

  template< typename Istream >
  Card1( iRecordStream< Istream >& is )
  try:
    ngendf( argument::extract< Ngendf >( is ) ),
    nout( argument::extract< Nout >( is, this->ngendf.value ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card1." );
    throw e;
  }
};
