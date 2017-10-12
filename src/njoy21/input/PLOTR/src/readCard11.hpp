template< typename Istream >
static optional< Card11 >
 readCard11( Istream& is, const int itype )
{

  if( itype < 0 ){
    Card11 card11( is );
    return optional< Card11 >( card11 );
  }
  return std::nullopt;
};
