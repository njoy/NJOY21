template< typename Istream >
std::vector< std::tuple< Card7, Card8, Card9 > > readCard789List( Istream& is,
                                                      const unsigned int ntype )
{
  std::vector< std::tuple< Card7, Card8, Card9 > > card789List;
  std::vector< Card7 > card7List;
  std::vector< Card8 > card8List;
  std::vector< Card9 > card9List;

  for( unsigned int i = 0; i < ntype; i++ ){
    try{
      card7List.emplace_back( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble reading Card7 values." );
      throw e;
    }
  }

  for( unsigned int i = 0; i < ntype; i++ ){
    try{
      card8List.emplace_back( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble reading Card8 values." );
      throw e;
    }
  }

  for( unsigned int i = 0; i < ntype; i++ ){
    try{
      card9List.emplace_back( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble reading Card9 values." );
      throw e;
    }
  }

  for( unsigned int i = 0; i < ntype; i++ ){
    card789List.push_back( std::make_tuple( std::move( card7List.at(i) ),
                                            std::move( card8List.at(i) ),
                                            std::move( card9List.at(i) ) ) );
  }

  return card789List;
}
