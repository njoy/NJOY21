class Card3 {
public:

  #include "njoy21/input/MATXSR/Card3/Npart.hpp"
  #include "njoy21/input/MATXSR/Card3/Ntype.hpp"
  #include "njoy21/input/MATXSR/Card3/Nholl.hpp"
  #include "njoy21/input/MATXSR/Card3/Nmat.hpp"

  Argument< Npart > npart;
  Argument< Ntype > ntype;
  Argument< Nholl > nholl;
  Argument< Nmat > nmat;

  template< typename Istream >
  Card3( Istream& is )
  try:
    npart( argument::extract< Npart >( is ) ),
    ntype( argument::extract< Ntype >( is ) ),
    nholl( argument::extract< Nholl >( is ) ),
    nmat( argument::extract< Nmat >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 3." );
    throw e;
  }
};
