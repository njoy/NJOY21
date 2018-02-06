class Card6 {
public:

  #include "njoy21/input/ACER/Card6/Newfor.hpp"
  #include "njoy21/input/ACER/Card6/Iopp.hpp"

  Argument< Newfor > newfor;
  Argument< Iopp > iopp;

  template< typename Char >
  Card6( iRecordStream< Char >& is, 
         const Argument< ACER::Card1::Ngend >& ngend )
    try:
      newfor( argument::extract< Newfor >( is ) ),
      iopp( argument::extract< Iopp >( is, ngend ) )
  {
    Card::clear( is );
  }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 6" );
      throw e;
    }
  
};
