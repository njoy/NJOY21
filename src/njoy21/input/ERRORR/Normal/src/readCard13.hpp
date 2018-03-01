template< typename Istream >
optional< Card13 > readCard13( Istream& is, const int iwt ){
  if( iwt != 1 ) return std::nullopt;

  return Card13( is );
}
