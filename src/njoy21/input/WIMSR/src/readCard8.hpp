template< typename Istream >
optional< Card8 > readCard8( Istream& is, const int jp1 ){
  if( jp1 <= 0 ){
    return std::nullopt;
  }

  return Card8( is, jp1 );
}
