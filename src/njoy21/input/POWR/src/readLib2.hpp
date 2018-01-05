template< typename Istream >
optional< std::vector< Lib2 > > readLib2( Istream& is, const int lib ){
  if( lib != 2 ) return std::nullopt;

  std::vector< Lib2 > lib2List;

  lib2List.emplace_back( is );

  while( lib2List.back().card3.matd.value != 0 ) lib2List.emplace_back( is );

  return lib2List;
}
