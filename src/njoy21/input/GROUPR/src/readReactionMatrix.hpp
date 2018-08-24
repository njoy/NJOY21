template< typename Istream >
static reactionMatrix_t
readReactionMatrix( Istream& is, 
                    Argument< Card2::Matb > matb, 
                    const Card4& card4 ){
  reactionMatrix_t matrix;

  matrix.emplace_back( makeMaterialReactions( is, matb.value, card4 ) );
  Card10 card10{ is };

  while( card10.matd.value != 0 ){
    matrix.emplace_back( 
        makeMaterialReactions( is, card10.matd.value, card4 ) );
    card10 = Card10{ is };
  } 

  return matrix;
}
