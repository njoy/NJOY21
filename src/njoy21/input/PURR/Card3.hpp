class Card3 {
public:
  /* nested types */
  #include "njoy21/input/PURR/Card3/Temp.hpp"

  Argument< Temp > temp;

  template< typename Char >
  Card3( iRecordStream< Char >& is,
         Argument< PURR::Card2::Ntemp >& ntemp)
    try:
      temp( argument::extract< Temp >( is, ntemp ) )
  {   
    Card::clear( is );
  }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 3" );
      throw e;
    }
};
