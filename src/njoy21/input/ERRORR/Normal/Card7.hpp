class Card7 {
public:

#include "njoy21/input/ERRORR/Normal/Card7/Iread.hpp"
#include "njoy21/input/ERRORR/Normal/Card7/Mfcov.hpp"
#include "njoy21/input/ERRORR/Normal/Card7/Irespr.hpp"
#include "njoy21/input/ERRORR/Normal/Card7/Legord.hpp"
#include "njoy21/input/ERRORR/Normal/Card7/Ifissp.hpp"
#include "njoy21/input/ERRORR/Normal/Card7/Efmean.hpp"
#include "njoy21/input/ERRORR/Normal/Card7/Dap.hpp"

Argument< Iread > iread;
Argument< Mfcov > mfcov;
Argument< Irespr > irespr;
Argument< Legord > legord;
Argument< Ifissp > ifissp;
Argument< Efmean > efmean;
Argument< Dap > dap;

template< typename Istream >
Card7( Istream& is, const int ngout )
try:
  iread( argument::extract< ERRORR::Normal::Card7::Iread >( is, ngout ) ),
  mfcov( argument::extract< ERRORR::Normal::Card7::Mfcov >( is, ngout ) ),
  irespr( argument::extract< ERRORR::Normal::Card7::Irespr >( is,
                                                          this->mfcov.value ) ),
  legord( argument::extract< ERRORR::Normal::Card7::Legord >( is,
                                                          this->mfcov.value ) ),
  ifissp( argument::extract< ERRORR::Normal::Card7::Ifissp >( is,
                                                          this->mfcov.value ) ),
  efmean( argument::extract< ERRORR::Normal::Card7::Efmean >( is,
                                      this->ifissp.value, this->mfcov.value ) ),
  dap( argument::extract< ERRORR::Normal::Card7::Dap >( is, this->mfcov.value ))
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card7." );
  throw e;
}
};
