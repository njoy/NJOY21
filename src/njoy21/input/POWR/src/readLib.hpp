template< typename Istream >
static std::variant< std::vector< Lib1 >, std::vector< Lib2 >, Lib3 >
readLib( Istream& is, const int lib, const int iclaps ){
  if( lib == 1 ) return readLib1( is );
  if( lib == 2 ) return readLib2( is );
  if( lib == 3 ) return Lib3( is, iclaps );
  Log::info("Provided lib value ({}) is not one of the allowed values (1,2,3).",
            lib );
  throw std::exception();
}
