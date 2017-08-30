class Card7 {
public:
  using Matd = GROUPR::Card10::Matd;
  
  Argument< Matd > matd;

  template< typename Char >
  Card7( iRecordStream< Char >& is  )
    try:
      matd( argument::extract< Matd >( is ) ){ Card::clear( is ); }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 7");
      throw e;
    }
};
