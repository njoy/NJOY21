template< typename Istream >
std::vector< Card4 > readCard4( Istream& is, const int niso ){
  std::vector< Card4 > card4List;

  for( int i = 0; i < niso; i++ ){
    card4List.emplace_back( is );   
  }

  return card4List;
}
