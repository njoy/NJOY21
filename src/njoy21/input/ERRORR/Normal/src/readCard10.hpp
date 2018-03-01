template< typename Istream >
optional< std::vector< Card10 > > readCard10List( Istream& is, const int iread){
  if( iread != 2 ) return std::nullopt;
  std::vector< Card10 > card10List;

  do{
    card10List.emplace_back( is );
  } while( card10List.back().mat1.value != 0 );

  card10List.pop_back();

  return card10List;
}
