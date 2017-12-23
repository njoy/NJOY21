class Card6b {
public:

  #include "njoy21/input/WIMSR/Card6b/Identa.hpp"
  #include "njoy21/input/WIMSR/Card6b/Lambda.hpp"

  Argument< Identa > identa;
  Argument< Lambda > lambda;

  template< typename Istream >
  Card6b( iRecordStream< Istream >& is )
  try:
    identa( argument::extract< WIMSR::Card6b::Identa >( is ) ),
    lambda( argument::extract< WIMSR::Card6b::Lambda >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 6b." );
    throw e;
  }
};
