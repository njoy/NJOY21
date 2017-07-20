class Card5a {
public:
  #include "njoy21/input/HEATR/Card5a/Qbar.hpp"

  Argument< Qbar > qbar;

  template< typename Char >
  Card5a( iRecordStream< Char >& is )
    try:
      qbar( argument::extract< Qbar >( is ) )
    {   
      Card::clear( is );
    } catch( std::exception& e ) {
      Log::info( "Trouble while validating HEATR card 5a" );
      throw e;
    }
};
