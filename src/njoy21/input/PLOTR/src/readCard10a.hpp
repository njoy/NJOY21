template< typename Istream >
static optional< Card10a >
 readCard10a( Istream& is, const int ileg )
{

  if( ileg == 2 ){
    Card10a card10a( is );
    return optional< Card10a >( card10a );
  }
  return std::nullopt;
};
