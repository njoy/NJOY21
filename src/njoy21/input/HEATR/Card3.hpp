class Card3 {
public:
  #include "njoy21/input/HEATR/Card3/Mtk.hpp"

  Argument< Mtk > mtk;

  template< typename Char >
  Card3( iRecordStream< Char >& is, Argument< HEATR::Card2::Npk >& npk)
    try:
      mtk( argument::extract< Mtk >( is, npk ) )
    {   
      Card::clear( is );
    } catch( std::exception& e ) {
      Log::info( "Trouble while validating HEATR card 3" );
      throw e;
    }
};
