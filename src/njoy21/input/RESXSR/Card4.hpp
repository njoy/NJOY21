class Card4 {
public:

  #include "njoy21/input/RESXSR/Card4/Holl.hpp"

  Argument< Holl > holl;

  template< typename Istream >
  Card4( Istream& is )
  try:
    holl( argument::extract< Holl >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating Card4." );
    throw e;
  }
};
