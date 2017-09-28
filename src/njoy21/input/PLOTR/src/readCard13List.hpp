template< typename Istream>
static std::vector< Card13 > readCard13List( Istream& is ){
  std::vector< Card13 > card13List;

  do {
    card13List.emplace_back( is );
  } while ( card13List.back().xdata.value );
  card13List.pop_back();
  return card13List;
}
