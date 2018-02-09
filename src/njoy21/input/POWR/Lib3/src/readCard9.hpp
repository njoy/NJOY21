template< typename Istream >
optional< std::vector< Card9 > > readCard9( Istream& is, const int if5,
                                            const size_t ntis ){
  if( if5 != 2 ) return std::nullopt;

  std::vector< Card9 > card9List;

  for( size_t i = 0; i < ntis; i++ ){
    card9List.emplace_back( is );
  }

  return card9List;
}
