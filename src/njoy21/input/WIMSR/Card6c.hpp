class Card6c {

  #include "njoy21/input/WIMSR/Card6c/Identa.hpp"
  #include "njoy21/input/WIMSR/Card6c/Yield.hpp"

  Argument< Identa > identa;
  Argument< Yield > yield;

  template< typename Istream >
  Card6c( Istream& is )
  try:
    identa( argument::extract< WIMSR::Card6c::Identa >( is ) ),
    yield( argument::extract< WIMSR::Card6c::Yield >( is ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 6c." );
    throw e;
  }
};
