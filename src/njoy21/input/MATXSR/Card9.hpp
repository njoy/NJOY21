class Card9{
public:

  #include "njoy21/input/MATXSR/Card9/Joutp.hpp"

  Argument< Joutp > joutpList;

  template< typename Istream >
  Card9( Istream& is, const int ntype )
  try:
    joutpList( argument::extract<MATXSR::Card9::Joutp>( is, ntype ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 9." );
    throw e;
  }
};
