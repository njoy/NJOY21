class Card2 {
public:

  #include "njoy21/input/RESXSR/Card2/Nmat.hpp"
  #include "njoy21/input/RESXSR/Card2/Maxt.hpp"
  #include "njoy21/input/RESXSR/Card2/Nholl.hpp"
  #include "njoy21/input/RESXSR/Card2/Efirst.hpp"
  #include "njoy21/input/RESXSR/Card2/Elast.hpp"
  #include "njoy21/input/RESXSR/Card2/Eps.hpp"

  Argument< Nmat > nmat;
  Argument< Maxt > maxt;
  Argument< Nholl > nholl;
  Argument< Efirst > efirst;
  Argument< Elast > elast;
  Argument< Eps > eps;

  template< typename Istream >
  Card2( Istream& is )
  try:
    nmat( argument::extract< Nmat >( is ) ),
    maxt( argument::extract< Maxt >( is ) ),
    nholl( argument::extract< Nholl >( is ) ),
    efirst( argument::extract< Efirst >( is ) ),
    elast( argument::extract< Elast >( is, this->efirst.value ) ),
    eps( argument::extract< Eps>( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating Card2." );
    throw e;
  }
};
