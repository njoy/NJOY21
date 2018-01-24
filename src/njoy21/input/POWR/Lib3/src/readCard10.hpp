template< typename Istream >
std::vector< optional< Card10 > > readCard10( Istream& is,
                       const std::vector< Card5 > card5List, const int iclaps ){
  std::vector< optional< Card10 > > card10List;

  int nres;

  if( iclaps == 1 ){
    nres = 15;
  } else {
    nres = 13;
  }

  for( auto card5 : card5List ){
    if(card5.nina.value == 0 or card5.nina.value == 3 or
       card5.nina03->first.value == 1){
      Card10 card10( is, nres );
      card10List.push_back( std::move( card10 ) );
      continue;
    }
    card10List.push_back( std::nullopt );
  }
  return card10List;
}
