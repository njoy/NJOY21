class Card3 {
public:

#include "njoy21/input/MIXR/Card3/Matn.hpp"
#include "njoy21/input/MIXR/Card3/Wtn.hpp"

#include "njoy21/input/MIXR/Card3/src/readMatnWtnList.hpp"

std::vector< std::pair< Argument< Matn >, Argument< Wtn > > > matnWtnList;

template< typename Istream >
Card3( Istream& is )
try:
  matnWtnList( readMatnWtnList( is ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card3." );
  throw e;
}
};
