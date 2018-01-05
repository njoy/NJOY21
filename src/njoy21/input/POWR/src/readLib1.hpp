template< typename Istream >
optional< std::vector< Lib1 > > readLib1( Istream& is, const int lib ){
  if( lib != 1 ) return std::nullopt;

  std::vector< Lib1 > lib1List;

  lib1List.emplace_back( is );

  while( lib1List.back().card3.matd.value != 0 ) lib1List.emplace_back( is );

  return lib1List;
}
