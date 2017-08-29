class Card3 {
public:
using Title = GROUPR::Card3::Title;

  Argument< Title > title;

  template< typename Char >
  Card3( iRecordStream< Char >& is )
    try:
      title( argument::extract< Title >( is ) )
    {
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 3");
      throw e;
    }
};
