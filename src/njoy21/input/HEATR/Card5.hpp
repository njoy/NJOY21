class Card5 {
public:
  #include "njoy21/input/HEATR/Card5/Qa.hpp"

  Argument< Qa > qa;

  template< typename Char >
  Card5( iRecordStream< Char >& is, Argument< HEATR::Card2::Nqa >& nqa )
    try:
      qa( argument::extract< Qa >( is, nqa ) )
    {   
      Card::clear( is );
    } catch( std::exception& e ) {
      Log::info( "Trouble while validating HEATR card 5" );
      throw e;
    }
};
