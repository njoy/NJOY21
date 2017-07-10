class Card10 {
public:

  Argument< argument::common::Matd > matd;
  Argument< argument::common::Tempd > tempd;

  template< typename Char >
  Card10( iRecordStream< Char >& is )
    try:
    matd( argument::extract< argument::common::Matd >( is ) ),
    tempd( argument::extract< argument::common::Tempd >( is ) )
  {
    Card::clear( is );
  }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 5" );
      throw e;
    }
};
