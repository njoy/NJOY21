template< typename Istream >
static optional< std::pair< Card12, optional< Card13 > > >
 readFreeform( Istream& is, const int iverf )
{
  if( iverf != 0 ) return std::nullopt;

  Card12 card12( is );

  if( card12.nform.value != 0 ){
    return std::pair< Card12, optional< Card13 > >(
                card12, std::nullopt);
  }

  Card13 card13;

  return std::pair< Card12, optional< Card13 > >(
              card12, card13( is ) );
}
