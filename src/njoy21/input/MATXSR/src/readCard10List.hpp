template< typename Istream >
std::vector< Card10 > readCard10List( Istream& is, const unsigned int nmat )
{
  std::vector< Card10 > card10List;

  for( unsigned int i = 0; i < nmat; i++ ){
    try{
      card10List.emplace_back( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble reading list of Card 10 values." );
      throw e;
    }
  }

  return card10List;
}
