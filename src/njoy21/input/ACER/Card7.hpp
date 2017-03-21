class Card7 {
public:
  #include "njoy21/input/ACER/Card7/Thin1.hpp"

  Argument< Thin1 > thin1;

  template< typename Char >
  Card7( iRecordStream< Char >& is )
  try:
    thin1( argument::extract< Thin1 >( is ) )
  {
    Card::clear( is );
  }
    catch( std::exception& e ){
      Log::info( "Trouble while validating Card 7" );
      throw e;
    }

};
