template< typename Istream >
static optional< Card4 > readCard4( Istream& is, const int iopt,
                                                             const int newmat ){
  if( iopt != 0 ) return std::nullopt;
  return Card4( is, newmat );
}
