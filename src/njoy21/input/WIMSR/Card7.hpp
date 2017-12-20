class Card7 {

  #include "njoy21/input/WIMSR/Card7/Lambda.hpp"

  Argument< Lambda > lambda;

  template< typename Istream >
  Card7( Istream& is, const int igroup, const int nrg )
  try:
    lambda( argument::extract< WIMSR::Card7::Lambda >( is, igroup, nrg ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 7." );
    throw e;
  }
};
