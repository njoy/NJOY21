template< typename Istream >
static optional< Card10 >
 readCard10( Istream& is, const int ileg )
{

  if( ileg != 0 ){
    Card10 card10( is );
    return optional< Card10 >( card10 );
  }
  return std::nullopt;
};
