template< typename Istream >
optional< Argument< Mt1 > > readMt1( Istream& is, const int mat1 ){
  if( mat1 == 0 ) return std::nullopt;

  return argument::extract< ERRORR::Normal::Card10::Mt1 >( is );
}
