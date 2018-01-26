template< typename Istream >
optional< Lib3 > readLib3( Istream& is, const int lib, const int iclaps ){
  if( lib != 3 ) return std::nullopt;
  return Lib3( is, iclaps );
}
