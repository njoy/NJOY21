class Card10 {
  public:
  #include "njoy21/input/LEAPR/Card10/Temp.hpp"

  Argument< Temp > temp;

  template< typename Char >
  Card10( iRecordStream<Char>& is )
  try:
    temp ( argument::extract< Temp  >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble while validating LEAPR Card10" );
    throw e;
  }
};
