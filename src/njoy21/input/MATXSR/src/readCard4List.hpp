template< typename Istream >
std::vector< Card4 > readCard4List( Istream& is, const unsigned int nholl )
{
  std::vector< Card4 > card4List;

  for( unsigned int i = 0; i < nholl; i++ ){
    try{
      card4List.emplace_back( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble reading list of Card 4 values." );
      throw e;
    }
  }

  return card4List;
}
