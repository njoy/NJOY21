template< typename Istream >
static optional< Plot > readPlot( Istream& is, const int iplot )
{
  if( std::abs( iplot ) != 1 ) return nullopt;
  return Plot( is );
}
