template< typename Istream >
static optional< Freeform > readFreeform( Istream& is, const int iverf )
{

  if( iverf != 0 ) return nullopt;

  return Freeform( is );
}
