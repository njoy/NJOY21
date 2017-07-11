class Card1 {
public:
using Nin = argument::common::Nin;

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
        Nout::Value_t  noutVal  = this->nout.value;
        Npend::Value_t npendVal = this->npend.value;
        Nplot::Value_t nplotVal = this->nplot.value;
        if ( (npendVal == 0 and nplotVal != 0)
          or (nplotVal == 0 and npendVal != 0) ){
          throw( "If npend/nplot goes unused (= 0), then so must the other" );
        }
        if ( npendVal == 0 and noutVal == 0 ){
          throw( "Invalid output option. Choose either nout or npend/nplot" );
        }
        
        Card::clear(is);
      }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card1");
      throw e;
    }
  
};
