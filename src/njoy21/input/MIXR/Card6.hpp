class Card6 {
  public:
  #include "njoy21/input/MIXR/Card6/Des.hpp"
  
  Argument< Des > des;

  template< typename Char >
  Card6( iRecordStream< Char >& is )
  try:
    des( argument::extract< Des >( is ) ){
      Card::clear( is );
    }
  catch( std::exception& e){
    Log::info( "Trouble while validating Card6" );
    throw e;
  }
};
