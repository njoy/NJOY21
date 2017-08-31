class Card5 {
public:

  using Wght = GROUPR::Card8b::Wght;

  Argument< Wght > wght;

  template< typename Char >
  Card5( iRecordStream< Char >& is )
    try:
      wght( argument::extract< Wght >( is ) )
      { 
        Card::clear( is );
      }
    catch( std::exception& e ) {
      Log::info( "Trouble while validating GAMINR card 5" );
      throw e;
    }
};
