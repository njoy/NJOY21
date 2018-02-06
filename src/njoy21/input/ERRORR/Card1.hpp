class Card1 {
public:

#include "njoy21/input/ERRORR/Card1/Nendf.hpp"
#include "njoy21/input/ERRORR/Card1/Npend.hpp"
#include "njoy21/input/ERRORR/Card1/Ngout.hpp"
#include "njoy21/input/ERRORR/Card1/Nout.hpp"
#include "njoy21/input/ERRORR/Card1/Nin.hpp"
#include "njoy21/input/ERRORR/Card1/Nstan.hpp"

Argument< Nendf > nendf;
Argument< Npend > npend;
Argument< Ngout > ngout;
Argument< Nout > nout;
Argument< Nin > nin;
Argument< Nstan > nstan;

template< typename Istream >
Card1( Istream& is )
try:
  nendf( argument::extract< ERRORR::Card1::Nendf >( is ) ),
  npend( argument::extract< ERRORR::Card1::Npend >( is, this->nendf.value ) ),
  ngout( argument::extract< ERRORR::Card1::Ngout >( is, this->nendf.value,
                                                          this->npend.value ) ),
  nout( argument::extract< ERRORR::Card1::Nout >( is, this->nendf.value,
                                       this->npend.value, this->ngout.value ) ),
  nin( argument::extract< ERRORR::Card1::Nin >( is, this->nendf.value,
                     this->npend.value, this->ngout.value, this->nout.value ) ),
  nstan( argument::extract< ERRORR::Card1::Nstan >( is, this->nendf.value,
     this->npend.value, this->ngout.value, this->nout.value, this->nin.value ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card1." );
  throw e;
}
};
