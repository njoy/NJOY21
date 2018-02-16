template< typename Istream >
optional< std::pair< Card12a, Card12b > > readCard12ab( Istream& is,
                                                        const int ign ){
  if( ign != 1 and ign != 19 ) return std::nullopt;

  Card12a card12a( is );
  Card12b card12b( is, card12a.ngn.value );

  return std::make_pair( std::move( card12a ), std::move( card12b ) );
}
