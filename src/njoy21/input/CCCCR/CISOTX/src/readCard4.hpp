template< typename Istream >
std::vector< Card4 > readCard4( Istream& is, const int ngroup ){
  std::vector< Card4 > card4List;

  for( int i = 0; i < ngroup; i++ ){
    card4List.emplace_back( is );   
  }

  return card4List;
}
