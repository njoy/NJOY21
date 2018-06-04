class Card6 {
public:

  #include "njoy21/input/ACER/Card6/Newfor.hpp"
  #include "njoy21/input/ACER/Card6/Iopp.hpp"
  #include "njoy21/input/ACER/Card6/Ismooth.hpp"

  Argument< Newfor > newfor;
  Argument< Iopp > iopp;
  Argument< Ismooth > ismooth;

  template< typename Char >
  Card6( iRecordStream< Char >& is )
    try:
      newfor( argument::extract< Newfor >( is ) ),
      iopp( argument::extract< Iopp >( is ) ),
      ismooth( argument::extract< Ismooth >( is ) )
  {
    Card::clear( is );
  }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 6" );
      throw e;
    }
  
};
