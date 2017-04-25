class Card4 {
public:
  /* nested types */
  #include "njoy21/input/GROUPR/Card4/Temp.hpp"

  Argument< Temp > temp;

  template< typename Char >
  Card4( iRecordStream< Char >& is, Argument< GROUPR::Card2::Ntemp >& ntemp)
    try:
      temp( argument::extract< Temp >( is, ntemp ) )
    {   
      Card::clear( is );
    } catch( std::exception& e ) {
      Log::info( "Trouble while validating card 3" );
      throw e;
    }
};
