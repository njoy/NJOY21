template< typename Istream >
static reactionMatrix_t
readReactionMatrix( Istream& is, Argument< Card2::Matb > matb, const Card4& card4 ){
  reactionMatrix_t matrix;

  std::vector< reactionList_t > reactions;
  for( auto& temp : card4.temp.value ){
    reactions.emplace_back( temp.value, readCard9List( is ) );
  }
  matrix.emplace_back( std::make_pair( matb.value, reactions ) );
  // for( int i = 0; i < ntemp; i++ ){
  //   matrix.emplace_back( 
  //       std::make_pair( readCard9List( is ), Card10{ is } )
  //   );
  // }

  return matrix;
}
