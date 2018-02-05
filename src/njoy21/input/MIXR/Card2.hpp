class Card2 {
public:

  #include "njoy21/input/MIXR/Card2/Mtn.hpp"

  #include "njoy21/input/MIXR/Card2/src/readMtn.hpp"

  std::vector< Argument< Mtn > > mtnList;

  template< typename Istream >
  Card2( Istream& is )
  try:
    mtnList( readMtn( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card2." );
    throw e;
  }
};
