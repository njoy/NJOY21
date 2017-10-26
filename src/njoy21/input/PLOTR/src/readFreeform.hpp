template< typename Istream >
static optional< Freeform > readFreeform( Istream& is, const int iverf )
{
  optional< Freeform > freeformCards;

  if( iverf != 0 ) return nullopt;

  Freeform tmpfree( is );
  *freeformCards = tmpfree;
  return freeformCards;
}
