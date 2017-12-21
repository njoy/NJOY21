class Card5 {
public:

  #include "njoy21/input/MATXSR/Card5/Hpart.hpp"

  Argument< Hpart > hpartList;

  template< typename Istream >
  Card5( Istream& is, const unsigned int npart )
  try:
    hpartList( argument::extract< MATXSR::Card5::Hpart >( is, npart ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 5." );
    throw e;
  }
};
