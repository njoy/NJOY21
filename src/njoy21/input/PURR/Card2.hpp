class Card2 {
public:

  /* nested types */
  #include "njoy21/input/PURR/Card2/Ntemp.hpp"
  #include "njoy21/input/PURR/Card2/Nsigz.hpp"
  #include "njoy21/input/PURR/Card2/Nbin.hpp"
  #include "njoy21/input/PURR/Card2/Nladr.hpp"
  #include "njoy21/input/PURR/Card2/Iprint.hpp"
  #include "njoy21/input/PURR/Card2/Nunx.hpp"

  Argument< RECONR::Card3::Mat > matd;
  Argument< Ntemp > ntemp;
  Argument< Nsigz > nsigz;
  Argument< Nbin > nbin;
  Argument< Nladr > nladr;
  Argument< Iprint > iprint;
  Argument< Nunx > nunx;

  template< typename Char >
  Card2( iRecordStream< Char >& is )
    try:
      matd( argument::extract< RECONR::Card3::Mat >( is ) ),
      ntemp( argument::extract< Ntemp >( is ) ),
      nsigz( argument::extract< Nsigz >( is ) ),
      nbin( argument::extract< Nbin >( is ) ),
      nladr( argument::extract< Nladr >( is ) ),
      iprint( argument::extract< Iprint >( is ) ),
      nunx( argument::extract< Nunx >( is ) )
  { 
    Card::clear( is );
  }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 2" );
      throw e;
    }
};
