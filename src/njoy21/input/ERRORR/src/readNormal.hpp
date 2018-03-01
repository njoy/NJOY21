template< typename Istream >
optional< Normal > readNormal( Istream& is, const int nendf, const int ngout,
                                        const int nstan ){
  if( nendf == 999 ) return std::nullopt;

  return Normal( is, ngout, nstan );
}
