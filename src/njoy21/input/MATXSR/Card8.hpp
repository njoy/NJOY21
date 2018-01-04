class Card8 {
public:

  #include "njoy21/input/MATXSR/Card8/Jinp.hpp"

  Argument< Jinp > jinpList;

  template< typename Istream >
  Card8( Istream& is, const int ntype )
  try:
    jinpList( argument::extract<MATXSR::Card8::Jinp>( is, ntype ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 8." );
    throw e;
  }
};
