template< typename Istream >
optional< std::vector< Lib2 > > readLib2( Istream& is, const int lib ){
  if( lib != 2 ) return std::nullopt;

  std::vector< Lib2 > lib2List;
  std::vector< Quantity< Kelvin > > tempList;

  lib2List.emplace_back( is );

  while( lib2List.back().card3.matd.value != 0 ){
    if( std::find( tempList.begin(), tempList.end(),
        lib2List.back().card3.idtemp.value ) == tempList.end() ){
      tempList.emplace_back( lib2List.back().card3.idtemp.value );
    }
    if( tempList.size() > 7 ){
      Log::error( "A maximum of 7 temperatures are allowed." );
      throw std::exception();
    }
    lib2List.emplace_back( is );
  }

  return lib2List;
}
