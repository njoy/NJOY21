class Card1 {

  using Ngendf = argument::common::nin;
  #include "njoy21/input/WIMSR/Card1/Nout.hpp"

  Ngendf ngendf;
  Nout nout;

  template< typename Istream >
  Card1( Istream& is )
  try:
    ngendf( is ),
    nout( is, this->ngendf.value )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card1." );
    throw e;
  }
};
