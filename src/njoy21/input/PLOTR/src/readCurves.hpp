template< typename Istream >
static std::vector< std::pair< Card2, Curves > >
 readCurves( Istream& is )
{
  std::vector< std::pair< Card2, Curves > > curveList;
  Card2 tmp2( is );

  do {
    Curves tmpc( is, tmp2.iplot.value );
    curveList.emplace_back( std::pair< Card2, Curves >(tmp2, tmpc) );
    Card2 tmp2( is );
  } while( tmp2.iplot.value != 99 );
  curveList.pop_back();

  return curveList;
}
