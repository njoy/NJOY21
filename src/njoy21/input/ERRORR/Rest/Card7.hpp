class Card7 {
public:

#include "njoy21/input/ERRORR/Rest/Card7/Iread.hpp"
#include "njoy21/input/ERRORR/Rest/Card7/Mfcov.hpp"
#include "njoy21/input/ERRORR/Rest/Card7/Irespr.hpp"
#include "njoy21/input/ERRORR/Rest/Card7/Legord.hpp"
#include "njoy21/input/ERRORR/Rest/Card7/Ifissp.hpp"
#include "njoy21/input/ERRORR/Rest/Card7/Efmean.hpp"
#include "njoy21/input/ERRORR/Rest/Card7/Dap.hpp"

#include "njoy21/input/ERRORR/Rest/Card7/src/readIrespr.hpp"
#include "njoy21/input/ERRORR/Rest/Card7/src/readLegord.hpp"
#include "njoy21/input/ERRORR/Rest/Card7/src/readIfisspEfmean.hpp"
#include "njoy21/input/ERRORR/Rest/Card7/src/readDap.hpp"

Argument< Iread > iread;
Argument< Mfcov > mfcov;
optional< Argument< Irespr > > irespr;
optional< Argument< Legord > > legord;
optional< std::pair< Argument< Ifissp >, Argument< Efmean > > > ifisspEfmean;
optional< Argument< Dap > > dap;

template< typename Istream >
Card7( Istream& is, const int ngout )
try:
  iread( argument::extract< ERRORR::Rest::Card7::Iread >( is, ngout ) ),
  mfcov( argument::extract< ERRORR::Rest::Card7::Mfcov >( is, ngout ) ),
  irespr( readIrespr( is, this->mfcov.value ) ), // mf = 32
  legord( readLegord( is, this->mfcov.value ) ), // mf = 34
  ifisspEfmean( readIfisspEfmean( is, this->mfcov.value ) ), // mf = 35
  dap( readDap( is, this->mfcov.value ) ) // mf = 33
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card7." );
  throw e;
}
};
