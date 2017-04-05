class GROUPR {
public:
  /* nested types */
  #include "njoy21/input/GROUPR/Card1.hpp"

  Card1 card1;

  template< typename Istream >
  GROUPR( Istream& is )
  try:
    card1( is )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating GROUPR input." );
    throw e;
  }
;
