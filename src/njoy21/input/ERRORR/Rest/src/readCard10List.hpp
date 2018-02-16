template< typename Istream >
optional< std::vector< Card10 > > readCard10List( Istream& is, const int iread )
{
  if( iread != 2 ) return std::nullopt;
  std::vector< Card10 > card10List;
  std::vector< int > used;

  do{
    card10List.emplace_back( is );
    auto dup = std::find( used.begin(), used.end(),
                                                 card10List.back().mat1.value );
    if( dup != used.end() ){
      Log::error( "Material ({}) provided twice.",
                                                 card10List.back().mat1.value );
      throw std::exception();
    }

    used.push_back( card10List.back().mat1.value );
  } while( card10List.back().mat1.value != 0 );

  card10List.pop_back();

  if( card10List.size() == 0 ){
    Log::error( "No valid Card10 values were provided." );
    throw std::exception();
  }

  return card10List;
}
