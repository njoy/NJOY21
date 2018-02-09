template< typename Istream >
static std::vector< Lib2 > readLib2( Istream& is ){
  std::vector< Lib2 > lib2List;
  std::vector< Quantity< Kelvin > > tempList;

  lib2List.emplace_back( is );

  while( lib2List.back().card3.matd.value != 0 ){
    if( std::find( tempList.begin(), tempList.end(),
        lib2List.back().card3.rest->first.value ) == tempList.end() ){
      tempList.emplace_back( lib2List.back().card3.rest->first.value );
    }
    if( tempList.size() > 7 ){
      Log::error( "A maximum of 7 temperatures are allowed." );
      throw std::exception();
    }
    lib2List.emplace_back( is );
  }

  return lib2List;
}
