template< typename Istream >
static optional< std::pair< Card7, Card7a > >
 readCard7( Istream& is, const int jtype )
{
  Card7 card7;
  Card7a card7a;

  if( std::abs( jtype ) != 0 ){
    return optional< std::pair< Card7, Card7a > >(
           card7( is, jtype ), card7a( is ) );
  }
  return std::nullopt;
}
