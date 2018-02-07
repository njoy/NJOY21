template< typename Istream >
static optional< std::pair< Card5, Card6 > > readCard56( Istream& is,
                                                                const int nek ){
  if( nek == 0 ) return std::nullopt;

  Card5 card5( is, nek );
  Card6 card6( is, nek );

  return std::make_pair( std::move( card5 ), std::move( card6 ) );
}
