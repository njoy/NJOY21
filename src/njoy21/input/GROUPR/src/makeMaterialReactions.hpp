template< typename Istream >
static materialReactionsPair_t
makeMaterialReactions( Istream& is, 
                       Card10::Matd::Value_t MAT,
                       const Card4& card4 ){

  tempReactionListPair_t reactions;
  for( auto temp : card4.temp.value ){
    reactions.emplace_back( temp, readCard9List( is ) );
  }
  return std::make_pair( MAT, reactions );
}
