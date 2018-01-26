template< typename Istream >
std::vector< optional< std::pair< Card11, Card11a > > > readCard11( Istream& is,
                                           const std::vector< Card5 > card5List,
                                      const std::vector< optional< Card10 > > ){
  std::vector< optional< std::pair< Card11, Card11a > > > card11List;

  for( size_t i = 0; i < card5List.size(); i++ ){
    if( card5List.at(i).nina.value != 3 ){
      card11List.push_back( std::nullopt );
    } else {
      Card11 card11( is, card10List.at(i)->lambda.value.size() );

      card11List.push_back( std::make_pair(std::move( card11 ),
                       Card11a( is, card10List.at(i)->lambda.value.size() ) ) );
    }
  }

  return card11List;
}
