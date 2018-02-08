template< typename Istream >
optional< Rest > readRest( Istream& is, const int nendf, const int ngout,
                                        const int nstan ){
  if( nendf == 999 ) return std::nullopt;

  return Rest( is, ngout, nstan );
}
