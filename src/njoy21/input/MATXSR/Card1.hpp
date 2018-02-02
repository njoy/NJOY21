class Card1 {
public:

  #include "njoy21/input/MATXSR/Card1/Ngen1.hpp"
  #include "njoy21/input/MATXSR/Card1/Ngen2.hpp"
  #include "njoy21/input/MATXSR/Card1/Nmatx.hpp"
  #include "njoy21/input/MATXSR/Card1/Ngen3.hpp"
  #include "njoy21/input/MATXSR/Card1/Ngen4.hpp"
  #include "njoy21/input/MATXSR/Card1/Ngen5.hpp"
  #include "njoy21/input/MATXSR/Card1/Ngen6.hpp"
  #include "njoy21/input/MATXSR/Card1/Ngen7.hpp"

  Argument< Ngen1 > ngen1;
  Argument< Ngen2 > ngen2;
  Argument< Nmatx > nmatx;
  Argument< Ngen3 > ngen3;
  Argument< Ngen4 > ngen4;
  Argument< Ngen5 > ngen5;
  Argument< Ngen6 > ngen6;
  Argument< Ngen7 > ngen7;

  template< typename Istream >
  Card1( Istream& is )
  try:
    ngen1( argument::extract< Ngen1 >( is ) ),
    ngen2( argument::extract< Ngen2 >( is, this->ngen1.value ) ),
    nmatx( argument::extract< Nmatx >( is, this->ngen2.value,
           this->ngen1.value ) ),
    ngen3( argument::extract< Ngen3 >( is, this->nmatx.value, this->ngen2.value,
           this->ngen1.value ) ),
    ngen4( argument::extract< Ngen4 >( is, this->ngen3.value, this->nmatx.value,
           this->ngen2.value, this->ngen1.value ) ),
    ngen5( argument::extract< Ngen5 >( is, this->ngen4.value, this->ngen3.value,
           this->nmatx.value, this->ngen2.value, this->ngen1.value ) ),
    ngen6( argument::extract< Ngen6 >( is, this->ngen5.value, this->ngen4.value,
           this->ngen3.value, this->nmatx.value, this->ngen2.value,
           this->ngen1.value ) ),
    ngen7( argument::extract< Ngen7 >( is, this->ngen6.value, this->ngen5.value,
           this->ngen4.value, this->ngen3.value, this->nmatx.value,
           this->ngen2.value, this->ngen1.value ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 1." );
    throw e;
  }
};
