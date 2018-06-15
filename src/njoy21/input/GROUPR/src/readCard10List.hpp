template< typename Istream>
static std::vector< Card10 > readCard10List( Istream& is ){
  std::vector< Card10 > card10List;

  do {
    card10List.emplace_back( is );
  } while ( card10List.back().matd.value );

  card10List.pop_back();
  return card10List;
}
