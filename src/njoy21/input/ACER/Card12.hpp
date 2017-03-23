class Card12 {
public:

  Argument< argument::common::Matd > matd;

  template< typename Char >
  Card12( iRecordStream< Char >& is )
    try:
    matd( argument::extract< argument::common::Matd >( is ) )
  {
    Card::clear( is );
  }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 11" );
      throw e;
    }
};
