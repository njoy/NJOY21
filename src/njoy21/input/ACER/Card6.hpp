class Card6 {
public:

  template< typename Char >
  Card6( iRecordStream< Char >& is )
    try:
  {
    Card::clear( is );
  }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 6" );
      throw e;
    }
  
};
