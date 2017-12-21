class Card5 {

  #include "njoy21/input/WIMSR/Card5/Ntis.hpp"
  #include "njoy21/input/WIMSR/Card5/Efiss.hpp"

  Argument< Ntis > ntis;
  Argument< Efiss > efiss;

  template< typename Istream >
  Card5( Istream& is )
  try:
    ntis( argument::extract< WIMSR::Card5::Ntis >( is ) ),
    efiss( argument::extract< WIMSR::Card5::Efiss >( is ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 5." );
    throw e;
  }
};
