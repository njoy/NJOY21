template< typename Istream >
static optional< Plot > readPlot( Istream& is, const int iplot )
{
  optional< Plot > plot;

  if( std::abs( iplot ) != 1 ) return nullopt;
  plot( is );

  return plot;
}
