class Card1 {
public:

using argument::common::Nin;
#include "njoy21/input/CCCCR/Card1/Nisot.hpp";
#include "njoy21/input/CCCCR/Card1/Nbrks.hpp";
#include "njoy21/input/CCCCR/Card1/Ndlay.hpp";

Argument< Nin > nin;
Argument< Nisot > nisot;
Argument< Nbrks > nbrks;
Argument< Ndlay > ndlay;

template< typename Istream >
Card1( Istream& is )
try:
  nin( argument::extract< argument::common::Nin >( is ) ),
  nisot( argument::extract< CCCCR::Card1::Nisot >( is, this->nin.value ) ),
  nbrks( argument::extract< CCCCR::Card1::Nbrks >( is, this->nisot.value,
                                                   this->nin.value ) ),
  ndlay( argument::extract< CCCCR::Card1::Ndlay >( is, this->nbrks.value,
                                          this->nisot.value, this->nin.value ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card1." );
  throw e;
}
};
