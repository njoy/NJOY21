template< typename Istream >
optional< CISOTX > readCISOTX( Istream& is, const int nisot, const int ngroup,
                               const int niso ){
  if( nisot == 0 ) return std::nullopt;

  return CISOTX( is, ngroup, niso );
}
