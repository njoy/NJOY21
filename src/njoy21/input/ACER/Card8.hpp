class Card8 {
public:

  #include "njoy21/input/ACER/Card8/Tempd.hpp"
  #include "njoy21/input/ACER/Card8/Tname.hpp"

  Argument< argument::common::Matd > matd;
  Argument< Tempd > tempd;
  Argument< Tname > tname;

  template< typename Char >
  Card8( iRecordStream< Char >& is )
    try:
    matd( argument::extract< argument::common::Matd >( is ) ),
    tempd( argument::extract< Tempd >( is ) ),
    tname( argument::extract< Tname >( is ) )
  {
    Card::clear( is );
  }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 8" );
      throw e;
    }
};
