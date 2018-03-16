template< typename Istream >
std::vector< Card5 > readCard5( Istream& is, const int mode,
                                const optional< Card4 > card4 ){
  std::vector< Card5 > card5List;
  if( card4 != std::nullopt ){
    for( size_t i = 0; i < card4->mat.value.size(); i++ ){
      card5List.emplace_back( is, mode );
    }
  }
  return card5List;
}
