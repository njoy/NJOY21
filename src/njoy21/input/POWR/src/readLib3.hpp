template< typename Istream >
optional< Lib3 > readLib3( Istream& is, const int lib ){
  if( lib != 3 ) return std::nullopt;
  return Lib3( is );
}
