template< typename Istream>
static std::vector< Card10 > readCard10List( Istream& is ){
  std::vector< Card10 > card10List;

  do {
    card10List.emplace_back( is );
  } while ( card10List.back().matd.value );
  return card10List;
}
