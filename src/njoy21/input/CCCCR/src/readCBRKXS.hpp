template< typename Istream >
optional< CBRKXS > readCBRKXS( Istream& is, const int nbrks ){
  if( nbrks == 0 ) return std::nullopt;

  return CBRKXS( is );
}
