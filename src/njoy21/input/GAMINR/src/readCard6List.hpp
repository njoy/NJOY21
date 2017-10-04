template< typename Istream>
static std::vector< Card6 > readCard6List( Istream& is ){
  std::vector< Card6 > card6List;

  do {
    card6List.emplace_back( is );
  } while ( card6List.back().mfd.value );
  card6List.pop_back();
  return card6List;
}
