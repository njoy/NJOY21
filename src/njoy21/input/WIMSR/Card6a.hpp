class Card6a {
public:

  #include "njoy21/input/WIMSR/Card6a/Identa.hpp"
  #include "njoy21/input/WIMSR/Card6a/Yield.hpp"

  Argument< Identa > identa;
  Argument< Yield > yield;

  template< typename Istream >
  Card6a( iRecordStream< Istream >& is )
  try:
    identa( argument::extract< WIMSR::Card6a::Identa >( is ) ),
    yield( argument::extract< WIMSR::Card6a::Yield >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 6a." );
    throw e;
  }
};
