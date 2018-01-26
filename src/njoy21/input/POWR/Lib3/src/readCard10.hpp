template< typename Istream >
std::vector< optional< Card10 > > readCard10( Istream& is,
                       const std::vector< Card5 > card5List, const int iclaps ){
  std::vector< optional< Card10 > > card10List;

  int nres = ( iclaps == 1 ) ? 15 : 13;

  for( auto card5 : card5List ){
    if(card5.nina.value == 0 or card5.nina.value == 3 ){
      card10List.push_back( Card10( is, nres ) );
    } else {
      card10List.push_back( std::nullopt );
    }
  }
  return card10List;
}
