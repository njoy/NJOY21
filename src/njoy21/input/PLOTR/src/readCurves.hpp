template< typename Istream >
static std::vector< std::pair< Card2, Curves > >
 readCurves( Istream& is, Argument< PLOTR::Card1::Lori>& lori )
{
  std::vector< std::pair< Card2, Curves > > curveList;
  Card2 tmp2( is, lori );

  while( tmp2.iplot.value != 99 ){
    Curves tmpc( is, tmp2.iplot.value );
    curveList.push_back( std::make_pair(tmp2, tmpc) );
    tmp2 = Card2( is, lori );
  }

  if( curveList.size() == 0 ){
    Log::error( "No curves were specified in PLOTR module." );
    throw std::exception();
  }

  return curveList;
}
