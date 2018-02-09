template< typename Istream >
optional< std::tuple< Card8, Card8a, optional< std::pair< Card8b,
                                                    std::vector< Card9 > > > > >
readIread1( Istream& is, const int iread ){
  if( iread != 1 ) return std::nullopt;

  Card8 card8( is );
  Card8a card8a( is, card8.nmt.value );

  if( card8.nek.value == 0 ){
    return std::make_tuple( std::move( card8 ), std::move( card8a ),
                            std::nullopt );
  } else {
    Card8b card8b( is, card8.nek.value );

    std::vector< Card9 > card9List;

    for( size_t i = 0; i < card8.nek.value; i++ ){
      for( size_t j = 0; j < card8.nmt.value; j++ ){
        card9List.emplace_back( is, card8.nmt.value, j );
      }
    }

    return std::make_tuple( std::move( card8 ), std::move( card8a ),
                            std::make_pair( std::move( card8b ),
                                            card9List ) );
  }
}
