class Dummy {
public:

#include "njoy21/input/ERRORR/Dummy/Card2.hpp"
#include "njoy21/input/ERRORR/Dummy/Card3.hpp"

#include "njoy21/input/ERRORR/Dummy/src/readCard3List.hpp"

Card2 card2;
std::vector< Card3 > card3List;

template< typename Istream >
Dummy( Istream& is )
try:
  card2( is ),
  card3List( readCard3List( is ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading ERRORR dummy input." );
  throw e;
}
};
