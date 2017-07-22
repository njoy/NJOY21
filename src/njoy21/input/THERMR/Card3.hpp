class Card3 {
public:
  #include "njoy21/input/THERMR/Card3/Tempr.hpp"

  Argument< Tempr > tempr;

  template< typename Char >
  Card3( iRecordStream< Char >& is, Argument< THERMR::Card2::Ntemp >& ntemp)
    try:
      tempr( argument::extract< Tempr >( is, ntemp ) )
    {   
      Card::clear( is );
    } catch( std::exception& e ) {
      Log::info( "Trouble while validating THERMR card 3" );
      throw e;
    }
};
