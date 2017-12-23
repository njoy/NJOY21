class Card4 {
public:

  #include "njoy21/input/WIMSR/Card4/Ntemp.hpp"
  #include "njoy21/input/WIMSR/Card4/Nsigz.hpp"
  #include "njoy21/input/WIMSR/Card4/Sgref.hpp"
  #include "njoy21/input/WIMSR/Card4/Ires.hpp"
  #include "njoy21/input/WIMSR/Card4/Sigp.hpp"
  #include "njoy21/input/WIMSR/Card4/Mti.hpp"
  #include "njoy21/input/WIMSR/Card4/Mtc.hpp"
  #include "njoy21/input/WIMSR/Card4/Ip1opt.hpp"
  #include "njoy21/input/WIMSR/Card4/Inorf.hpp"
  #include "njoy21/input/WIMSR/Card4/Isof.hpp"
  #include "njoy21/input/WIMSR/Card4/Ifprod.hpp"
  #include "njoy21/input/WIMSR/Card4/Jp1.hpp"

  Argument< Ntemp > ntemp;
  Argument< Nsigz > nsigz;
  Argument< Sgref > sgref;
  Argument< Ires > ires;
  Argument< Sigp > sigp;
  Argument< Mti > mti;
  Argument< Mtc > mtc;
  Argument< Ip1opt > ip1opt;
  Argument< Inorf > inorf;
  Argument< Isof > isof;
  Argument< Ifprod > ifprod;
  Argument< Jp1 > jp1;

  template< typename Istream >
  Card4( iRecordStream< Istream >& is )
  try:
    ntemp( argument::extract< WIMSR::Card4::Ntemp >( is ) ),
    nsigz( argument::extract< WIMSR::Card4::Nsigz >( is ) ),
    sgref( argument::extract< WIMSR::Card4::Sgref >( is ) ),
    ires( argument::extract< WIMSR::Card4::Ires >( is ) ),
    sigp( argument::extract< WIMSR::Card4::Sigp >( is ) ),
    mti( argument::extract< WIMSR::Card4::Mti >( is ) ),
    mtc( argument::extract< WIMSR::Card4::Mtc >( is ) ),
    ip1opt( argument::extract< WIMSR::Card4::Ip1opt >( is ) ),
    inorf( argument::extract< WIMSR::Card4::Inorf >( is ) ),
    isof( argument::extract< WIMSR::Card4::Isof >( is ) ),
    ifprod( argument::extract< WIMSR::Card4::Ifprod >( is ) ),
    jp1( argument::extract< WIMSR::Card4::Jp1 >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card4." );
    throw e;
  }
};
