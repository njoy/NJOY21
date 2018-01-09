template< typename Istream >
std::vector< optional< Card10 > > readCard10( Istream& is,
                                         const std::vector< Card5 > card5List ){
  std::vector< optional< Card10 > > card10List;

  for( auto card5 : card5List ){
    if(card5.nina.value == 0 or card5.nina.value == 3 or card5.ires.value == 1){
      card10List.emplace_back( is );
      continue;
    }
    card10List.push_back( std::nullopt );
  }
  return card10List;
}
