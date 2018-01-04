template< typename Istream >
Card7 readCard7( Istream& is, const int igroup, optional< Card2a > card2a ){
  if( igroup == 0 && card2a == std::nullopt ){
    return Card7( is, igroup, 13 );
  } else {
    return Card7( is, igroup, card2a->nrg.value );
  }
}
