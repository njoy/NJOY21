template< typename Istream >
std::vector< optional< std::pair< Card11, Card11a > > > readCard11( Istream& is,
                                         const std::vector< Card5 > card5List ){
  std::vector< optional< std::pair< Card11, Card11a > > > card11List;

  for( auto card5 : card5List ){
    if( card5.nina.value != 3 ){
      card11List.push_back( std::nullopt );
      continue;
    }

    Card11 card11( is );

    card11List.push_back( std::make_pair( std::move( card11 ), Card11a( is ) ));
  }

  return card11List;
}
