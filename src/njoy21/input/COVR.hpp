class COVR {
public:
#include "njoy21/input/COVR/Card1.hpp"
Card1 card1;

template <typename Char> 
  COVR( iRecordStream<Char>& iss )
  try:
    card1( iss ){}
  catch( std::exception &e ){
    Log::info( "Trouble with validating COVR input" );
    throw e;
  }
};
