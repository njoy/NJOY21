template< typename Istream >
static std::vector< std::pair< std::vector< Card9 >, Card10 > >
readReactionMatrix( Istream& is, const int ntemp ){
  std::vector< std::pair< std::vector< Card9 >, Card10 > > matrix;

  for( int i = 0; i < ntemp; i++ ){
    matrix.emplace_back( 
        std::make_pair( readCard9List( is ), Card10{ is } )
    );
  }

  return matrix;
}
