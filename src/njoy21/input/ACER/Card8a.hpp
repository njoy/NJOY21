class Card8a {
public:

  #include "njoy21/input/ACER/Card8a/Iza01.hpp"
  #include "njoy21/input/ACER/Card8a/Iza02.hpp"

  Argument< Iza01> iza01;
  Argument< Iza02> iza02;
  Argument< Iza02> iza03;

  template< typename Char >
  Card8a( iRecordStream< Char >& is )
    try:
    iza01( argument::extract< Iza01 >( is ) ),
    iza02( argument::extract< Iza02 >( is ) ),
    iza03( argument::extract< Iza02 >( is ) )
  {
    Card::clear( is );
  }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 8a" );
      throw e;
    }
};

