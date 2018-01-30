class Card4 {
public:

#include "njoy21/input/CCCCR/CISOTX/Card4/Kbr.hpp"
#include "njoy21/input/CCCCR/CISOTX/Card4/Amass.hpp"
#include "njoy21/input/CCCCR/CISOTX/Card4/Efiss.hpp"
#include "njoy21/input/CCCCR/CISOTX/Card4/Ecapt.hpp"
#include "njoy21/input/CCCCR/CISOTX/Card4/Temp.hpp"
#include "njoy21/input/CCCCR/CISOTX/Card4/Sigpot.hpp"
#include "njoy21/input/CCCCR/CISOTX/Card4/Adens.hpp"

Argument< Kbr > kbr;
Argument< Amass > amass;
Argument< Efiss > efiss;
Argument< Ecapt > ecapt;
Argument< Temp > temp;
Argument< Sigpot > sigpot;
Argument< Adens > adens;

template< typename Istream >
Card4( Istream& is )
try:
  kbr( argument::extract< CCCCR::CISOTX::Card4::Kbr >( is ) ),
  amass( argument::extract< CCCCR::CISOTX::Card4::Amass >( is ) ),
  efiss( argument::extract< CCCCR::CISOTX::Card4::Efiss >( is ) ),
  ecapt( argument::extract< CCCCR::CISOTX::Card4::Ecapt >( is ) ),
  temp( argument::extract< CCCCR::CISOTX::Card4::Temp >( is ) ),
  sigpot( argument::extract< CCCCR::CISOTX::Card4::Sigpot >( is ) ),
  adens( argument::extract< CCCCR::CISOTX::Card4::Adens >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card4." );
  throw e;
}
};
