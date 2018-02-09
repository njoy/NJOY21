template< typename Istream >
std::vector< RESXSR::Card5 > readCard5List( Istream& is, const int nmat ){
  std::vector< RESXSR::Card5 > card5List;

  for( int i = 0; i < nmat; i++ ){
    try{ card5List.emplace_back( is ); }
    catch( std::exception& e ){
      Log::info( "Trouble reading the list of Card5 values." );
      throw e;
    }
  }

  try{ card5List.emplace_back( is ); }
  catch( std::exception& e ){
    return card5List;
  }

  Log::error( "Too many Card5 entries." );
  throw std::exception();
}
