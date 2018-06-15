class Card8 {
public:
  #include "njoy21/input/PLOTR/Card8/Iverf.hpp"
  #include "njoy21/input/PLOTR/Card8/Nin.hpp"
  #include "njoy21/input/PLOTR/Card8/Matd.hpp"
  #include "njoy21/input/PLOTR/Card8/Mfd.hpp"
  #include "njoy21/input/PLOTR/Card8/Mtd.hpp"
  #include "njoy21/input/PLOTR/Card8/Temper.hpp"
  #include "njoy21/input/PLOTR/Card8/Nth.hpp"
  #include "njoy21/input/PLOTR/Card8/Ntp.hpp"
  #include "njoy21/input/PLOTR/Card8/Nkh.hpp"
  #include "njoy21/input/PLOTR/src/readNtpNkh.hpp"

  Argument< Iverf > iverf;
  Argument< Nin > nin;
  Argument< Matd > matd;
  Argument< Mfd > mfd;
  Argument< Mtd > mtd;
  Argument< Temper > temper;
  Argument< Nth > nth;
  optional< std::pair< Argument< Ntp >, Argument< Nkh > > > ntpnkh;

  template< typename Char >
  Card8 ( iRecordStream< Char >& is, const int jtype )
    try:
      iverf( argument::extract< Iverf >( is ) ),
      nin( argument::extract< Nin >( is, this->iverf.value ) ),
      matd( argument::extract< Matd >( is, this->iverf.value ) ),
      mfd( argument::extract< Mfd >( is, this->iverf.value ) ),
      mtd( argument::extract< Mtd >( is, this->iverf.value ) ),
      temper( argument::extract< Temper >( is, this->iverf.value ) ),
      nth( argument::extract< Nth >( is, this->mfd.value,
                                     this->iverf.value, jtype ) ),
      ntpnkh( readNtpNkh( is, this->mfd.value, this->iverf.value ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card8" );
      throw e;
    }
};
