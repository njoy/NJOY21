template< typename Istream >
static optional< Card9 > readCard9( Istream& is, const int itype )
{
  if( itype > 0 ){
    return Card9( is );
  }
  return std::nullopt;
}
