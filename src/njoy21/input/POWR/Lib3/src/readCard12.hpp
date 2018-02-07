template< typename Istream >
static optional< std::vector< optional< std::pair< Card12, 
    std::pair< Card12a, std::vector< std::pair< Card12b,
    optional< Card12c > > > > > > > >
    readCard12( Istream& is, const std::vector< Card5 > card5List,
                                                             const int iclaps ){
      std::vector< optional< std::pair< Card12, std::pair< Card12a,
                std::vector< std::pair< Card12b, optional< Card12c > > > > > > >
                  retval;
      int l = 0;

      const size_t ngnd = ( iclaps == 0 ) ? 69 : 185;

      for( auto card5 : card5List ){
        const int nina = card5.nina.value;
        if( nina != 3 ){
          retval.push_back( std::nullopt );
          continue;
        }
        l++;

        Card12 card12( is, ngnd );
        Card12a card12a( is, ngnd );

        std::vector< std::pair< Card12b, optional< Card12c > > > bcList;

        for( size_t i = 0; i < ngnd; i++ ){
          Card12b card12b( is, ngnd );
          if( card12b.ia.value <= 0 ){
            bcList.push_back( std::make_pair( std::move( card12b ),
                                                               std::nullopt ) );
            continue;
          }

          bcList.push_back( std::make_pair( std::move( card12b ), Card12c( is,
                                  card12b.l2.value - card12b.l1.value + 1 ) ) );
        }

        retval.push_back( std::make_pair( std::move( card12 ), std::make_pair(
                                std::move( card12a ), std::move( bcList ) ) ) );
      }

      if( l == 0 ) return std::nullopt;

      return retval;
}
