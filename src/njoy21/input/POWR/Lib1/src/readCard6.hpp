template< typename Istream >
optional< Card6 > readCard6( Istream& is, const int matd ){
  if( matd >= 0 ) return std::nullopt;

  return POWR::Lib3::Card6( is );
}
