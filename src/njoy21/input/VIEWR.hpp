class VIEWR {
public:
#include "njoy21/input/VIEWR/Card1.hpp"
Card1 card1;

template <typename Char> 
  VIEWR( iRecordStream<Char>& iss )
  try:
    card1( iss ){}
  catch( std::exception &e ){
    Log::info( "Trouble with validating VIEWR input" );
    throw e;
  }
};
