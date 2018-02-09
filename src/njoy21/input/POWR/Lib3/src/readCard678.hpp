template< typename Istream >
optional< std::tuple< Card6, Card7, std::vector< Card8 > > > readCard678(
          Istream& is, const int if5 ){
  if( if5 <= 0 ) return std::nullopt;

  Card6 card6( is );
  Card7 card7( is, card6.nfis.value );
  std::vector< Card8 > card8List;

  for( int i = 0; i < card6.ntis.value; i++ ){
    card8List.emplace_back( is, card6.nfis.value );
  }

  return std::make_tuple( std::move( card6 ), std::move( card7 ),
                          std::move( card8List ) );
}
