template< typename Istream >
std::vector< optional< std::pair< Card12, 
    optional< std::pair< Card12a, std::vector< Card12b,
    optional< Card12c > > > > > > >
    readCard12( Istream& is, std::vector< Card5 > card5List ){
      std::vector< optional< std::pair< Card12, optional< std::pair< Card12a,
              std::vector< std::pair< Card12b, optional< Card12c > > > > > > > >
              retval;

      for( auto card5 : card5List ){
        if( card5.nina.value < 3 ){
          retval.push_back( std::nullopt );
          continue;
        }

        Card12 card12( is );

        if( card5.nina.value !=3 ){
          retval.push_back( std::make_pair( card12, std::nullopt ) );
          continue;
        }

        Card12a card12a( is );

        std::vector< std::pair< Card12b, optional< Card12c > > > bcList;

        for( size_t i = 0; i < 69; i++ ){
          Card12b card12b( is );
          if( card12b.ia.value <= 0 ){
            bcList.push_back( std::make_pair( card12b, std::nullopt ) );
            continue;
          }

          Card12c card12c( is, card12b.l2.value - card12b.l1.value + 1 );
          bcList.push_back( std::make_pair( card12b, card12c ) );
        }

        retval.push_back( std::make_pair( card12, std::make_pair( card12a,
          bcList ) ) );
      }

      return retval;
}
