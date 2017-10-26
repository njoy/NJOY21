template< typename Istream >
static optional< std::pair< Card7, Card7a > >
 readCard7( Istream& is, const int jtype )
{
  if( std::abs( jtype ) != 0 ){
    Card7 card7( is, jtype );

    return std::make_pair< Card7, Card7a >( std::move(card7), Card7a( is ) );
  }
  return std::nullopt;
}
