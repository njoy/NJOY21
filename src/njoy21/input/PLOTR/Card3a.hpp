class Card3a {
public:
//  template< typename S >
//  using Title = Card3::Title< S >;

  using T2 = Card3::Title< hana::string<'t','2'> >;
  Argument< T2 > t2;

  template< typename Char >
  Card3a( iRecordStream< Char >& is )
    try:
      t2( argument::extract< T2 >( is ) )
    {
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 3a - Title line 2");
      throw e;
    }
};
