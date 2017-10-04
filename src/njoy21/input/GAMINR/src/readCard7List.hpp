template< typename Istream>
static std::vector< Card7 > readCard7List( Istream& is ){
  std::vector< Card7 > card7List;

  do {
    card7List.emplace_back( is );
  } while ( card7List.back().matd.value );
  card7List.pop_back();
  return card7List;
}
