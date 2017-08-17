class Card9 {
  public:
  #include "njoy21/input/LEAPR/Card9/Beta.hpp"

  Argument< Beta > beta;

  template< typename Char >
  Card9( iRecordStream<Char>& is, Argument< LEAPR::Card7::Nbeta >& nbeta )
  try:
    beta ( argument::extract< Beta  >( is, nbeta ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble while validating LEAPR Card9" );
    throw e;
  }
};
