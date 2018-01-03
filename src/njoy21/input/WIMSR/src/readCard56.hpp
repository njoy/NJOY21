template< typename Istream >
optional< std::tuple< Card5, Card6a, Card6b, 
                      optional< std::vector< Card6c > > > >
readCard56( Istream& is, const int iburn ){
  if( iburn < 1 ) return std::nullopt;
  Card5 card5( is );
  Card6a card6a( is );
  Card6b card6b( is );
  if( card5.ntis.value < 3 ){
    return std::tuple< Card5, Card6a, Card6b, optional< std::vector< Card6c >>>(
                       card5, card6a, card6b, std::nullopt );
  }
  std::vector< Card6c > card6cList;
  for( auto i = 0; i < card5.ntis.value - 2; i++ ){
    card6cList.emplace_back( is );
  }
  return std::tuple< Card5, Card6a, Card6b, std::vector< Card6c > >(
                     card5, card6a, card6b, card6cList );
}
