class Card8 {
public:

  #include "njoy21/input/ACER/Card8/Tname.hpp"

  Argument< argument::common::Matd > matd;
  Argument< argument::common::Tempd > tempd;
  Argument< Tname > tname;

  template< typename Char >
  Card8( iRecordStream< Char >& is )
    try:
    matd( argument::extract< argument::common::Matd >( is ) ),
    tempd( argument::extract< argument::common::Tempd >( is ) ),
    tname( argument::extract< Tname >( is ) )
  {
    Card::clear( is );
  }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 8" );
      throw e;
    }
};
