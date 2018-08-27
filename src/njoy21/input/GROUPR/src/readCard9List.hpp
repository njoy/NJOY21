template< typename Istream >
static reactionList_t
readCard9List( Istream& is ){
  reactionList_t card9List;

  do {
    card9List.emplace_back( is );
  } while ( card9List.back().mfd.value );
  card9List.pop_back();

  return card9List;
}
