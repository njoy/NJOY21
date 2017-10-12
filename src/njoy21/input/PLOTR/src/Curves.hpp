class Curves {
  public:
  optional< Plot > plot;
  Card8 card8;
  Card9 card9;
  optional< Card10 > card10;
  optional< Card10a > card10a;
  optional< Card11 > card11;
  optional< std::pair< Card12, optional< Card13 > > > freeform;

  template< typename Istream >
  Curves( Istream& is, const int iplot )
  try:
    plot( readPlot( is, iplot ) ),
    card8( is ),
    card9( is ),
    card10( is, this->plot->card4.ileg.value ),
    card10a( is, this->plot->card4.ileg.value ),
    card11( is, this->plot->card4.itype.value ),
    freeform( is, this->card8.iverf.value )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating PLOTR Curve input\n"
               "(Card2-13)." );
    throw e;
  }
};
