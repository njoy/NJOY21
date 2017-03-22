class Card5 {
public:

  #include "njoy21/input/ACER/Card5/Tempd.hpp"

  Argument< argument::common::Matd > matd;
  Argument< Tempd > tempd;

  template< typename Char >
  Card5( iRecordStream< Char >& is )
    try:
    matd( argument::extract< argument::common::Matd >( is ) ),
    tempd( argument::extract< Tempd >( is ) )
  {
    Card::clear( is );
  }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 5" );
      throw e;
    }
};
