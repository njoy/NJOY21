template< typename Istream >
std::vector< std::pair< Card5, Card6 > > readCard56List( Istream& is,
                                                     const unsigned int npart )
{
  std::vector< std::pair< Card5, Card6 > > card56List;
  std::vector< Card5 > card5List;
  std::vector< Card6 > card6List;

  for( unsigned int i = 0; i < npart; i++ ){
    try{
      card5List.emplace_back( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble reading list of Card5 values." );
      throw e;
    }
  }

  for( unsigned int i = 0; i < npart; i++ ){
    try{
      card6List.emplace_back( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble reading list of Card6 values." );
      throw e;
    }
  }

  for( unsigned int i = 0; i < npart; i++ ){
    card56List.push_back( std::make_pair( std::move( card5List.at(i) ), 
                                          std::move( card6List.at(i) ) ) );
  }

  return card56List;
}
