class Card6c {
public:

  #include "njoy21/input/WIMSR/Card6c/Identa.hpp"
  #include "njoy21/input/WIMSR/Card6c/Yield.hpp"

  Argument< Identa > identa;
  Argument< Yield > yield;

  template< typename Istream >
  Card6c( iRecordStream< Istream >& is )
  try:
    identa( argument::extract< WIMSR::Card6c::Identa >( is ) ),
    yield( argument::extract< WIMSR::Card6c::Yield >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 6c." );
    throw e;
  }
};
