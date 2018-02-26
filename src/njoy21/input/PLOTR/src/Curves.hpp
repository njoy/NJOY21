class Curves {
  public:
  optional< Plot > plot;
  Card8 card8;
  optional< Card9 > card9;
  optional< Card10 > card10;
  optional< Card10a > card10a;
  optional< Card11 > card11;
  optional< Freeform > freeform;

  template< typename Istream >
  Curves( Istream& is, const int iplot )
  try:
    plot( readPlot( is, iplot ) ),
    card8( is, this->plot->card4.jtype.value ),
    card9( readCard9( is, this->plot->card4.itype.value ) ),
    card10( readCard10(is, this->plot->card4.ileg.value ) ),
    card10a( readCard10a(is, this->plot->card4.ileg.value ) ),
    card11( readCard11(is, this->plot->card4.itype.value ) ),
    freeform( readFreeform( is, this->card8.iverf.value ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating Curve input (Card2-13)." );
    throw e;
  }
};
