template< typename Istream >
static std::vector< Material > readMaterials( Istream& is ){
  std::vector< Material > materialList;

  do {
    materialList.emplace_back( is );
  } while ( materialList.back().card7.matd.value );

  return materialList;
}
