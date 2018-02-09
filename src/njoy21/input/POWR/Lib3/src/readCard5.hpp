template< typename Istream >
std::vector< Card5 > readCard5( Istream& is, const int mode,
                                const size_t num_mat ){
  std::vector< Card5 > card5List;
  for( size_t i = 0; i < num_mat; i++ ){
    card5List.emplace_back( is, mode );
  }
  return card5List;
}
