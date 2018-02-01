template< typename Istream >
std::vector< Card5 > readCard5( Istream& is, const int niso ){
  std::vector< Card5> card5List;

  for( int i = 0; i < niso; i++ ){
    card5List.emplace_back( is );
  }

  return std::move( card5List );
}
