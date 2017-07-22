class Card4 {
public:
  #include "njoy21/input/HEATR/Card4/Mta.hpp"

  Argument< Mta > mta;

  template< typename Char >
  Card4( iRecordStream< Char >& is, Argument< HEATR::Card2::Nqa >& nqa )
    try:
      mta( argument::extract< Mta >( is, nqa ) )
    {   
      Card::clear( is );
    } catch( std::exception& e ) {
      Log::info( "Trouble while validating HEATR card 4" );
      throw e;
    }
};
