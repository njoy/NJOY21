class Card7 {
public:
  #include "njoy21/input/ACER/Card7/Thin1.hpp"
  #include "njoy21/input/ACER/Card7/Thin2.hpp"
  #include "njoy21/input/ACER/Card7/Thin3.hpp"

  Argument< Thin1 > thin1;
  Argument< Thin2 > thin2;
  Argument< Thin3 > thin3;

  template< typename Char >
  Card7( iRecordStream< Char >& is )
  try:
    thin1( argument::extract< Thin1 >( is ) ),
    thin2( argument::extract< Thin2 >( is, thin1 ) ),
    thin3( argument::extract< Thin3 >( is, thin1 ) )
  {
    Card::clear( is );
  }
    catch( std::exception& e ){
      Log::info( "Trouble while validating Card 7" );
      throw e;
    }

};
