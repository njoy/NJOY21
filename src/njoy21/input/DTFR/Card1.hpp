class Card1 {
public:
#include "njoy21/input/DTFR/Card1/Nin.hpp"
#include "njoy21/input/DTFR/Card1/Nout.hpp"
#include "njoy21/input/DTFR/Card1/Npend.hpp"
#include "njoy21/input/DTFR/Card1/Nplot.hpp"

  Argument< Nin > nin;
  Argument< Nout > nout;
  Argument< Npend > npend;
  Argument< Nplot > nplot;
  
  template< typename Char >
  Card1( iRecordStream< Char >& is )
    try:
      nin( argument::extract< Nin >(is) ),
      nout( argument::extract< Nout >(is, this->nin) ),
      npend( argument::extract< Npend >(is, this->nin, this->nout) ),
      nplot(argument::extract< Nplot >(is, this->nin, this->nout, this->npend) )
      {
        Card::clear(is);
      }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card1");
      throw e;
    }
  
};
