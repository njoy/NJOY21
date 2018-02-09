template< typename Istream >
std::vector< Card4 > readCard4List( Istream& is,
 optional< std::tuple< Card2, optional< Card2z >, Card2a, Card3a > > card23a,
 optional< std::tuple< Card2b, Card3b, Card3c > > ){
  int ncase;
  if( card23a != std::nullopt and card23b != std::nullopt ){
    Log::error( "Both Card23a and Card23b exist, but only one is required." );
    throw std::exception();
  } else if( card23a != std::nullopt ){
    ncase = std::get< Card3a >( *( card23a ) ).ncase.value;
  } else if( card23b != std::nullopt ){
    ncase = std::get< Card2b >( *( card23b ) ).ncase.value;
  } else {
    Log::info( "Neither Card23a nor Card23b exist, but one is required." );
    throw std::exception();
  }

  std::vector< Card4 > card4List;

  for( int i = 0; i < ncase; i++ ){
    card4List.emplace_back( is );
  }

  return card4List;
}
