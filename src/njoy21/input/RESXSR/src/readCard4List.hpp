template< typename Istream >
std::vector< RESXSR::Card4 > readCard4List( Istream& is, const int nholl ){
  std::vector< RESXSR::Card4 > card4List;

  for( int i = 0; i < nholl; i++ ){
    try{ card4List.emplace_back( is ); }
    catch( std::exception& e ){
      Log::info( "Trouble reading the list of Card4 values." );
      throw e;
    }
  }

  return card4List;
}
