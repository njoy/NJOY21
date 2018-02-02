template< typename Istream >
static std::vector< Material > readMaterials( Istream& is ){
  std::vector< Material > materialList;

  materialList.emplace_back( is );

  if( materialList.back().card7.matd.value == 0 ) return materialList;

  do {
    materialList.emplace_back( is );
  } while ( materialList.back().card7.matd.value );

  return materialList;
}
