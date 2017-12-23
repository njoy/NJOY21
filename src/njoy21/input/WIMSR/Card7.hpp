class Card7 {
public:

  #include "njoy21/input/WIMSR/Card7/Lambda.hpp"

  Argument< Lambda > lambda;

  template< typename Istream >
  Card7( iRecordStream< Istream >& is, const int igroup, const int nrg )
  try:
    lambda( argument::extract< WIMSR::Card7::Lambda >( is, igroup, nrg ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 7." );
    throw e;
  }
};
