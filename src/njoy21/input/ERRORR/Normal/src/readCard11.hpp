template< typename Istream >
optional< std::vector< Card11 > > readCard11( Istream& is, const int nstan ){
  if( nstan == 0 ) return std::nullopt;
  std::vector< Card11 > card11List;

  do{
    card11List.emplace_back( is );
  } while( card11List.back().matb.value != 0 );

  card11List.pop_back();

  if( card11List.size() == 0 ){
    Log::error( "No valid Card11 values were provided." );
    throw std::exception();
  }

  return card11List;
}
