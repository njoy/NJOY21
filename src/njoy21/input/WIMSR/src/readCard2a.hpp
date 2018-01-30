template< typename Istream >
optional< Card2a > readCard2a( Istream& is, const int igroup ){
  if( igroup != 9 ) return std::nullopt;
  return Card2a( is );
}
