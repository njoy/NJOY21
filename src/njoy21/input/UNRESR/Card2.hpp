class Card2 {
public:
  /* nested types */
  #include "njoy21/input/PURR/Card2/Ntemp.hpp"
  #include "njoy21/input/PURR/Card2/Nsigz.hpp"
  #include "njoy21/input/UNRESR/Card2/Iprint.hpp"

  Argument< RECONR::Card3::Mat > matd;
  Argument< PURR::Card2::Ntemp > ntemp;
  Argument< PURR::Card2::Nsigz > nsigz;
  Argument< Iprint > iprint;

  template< typename Char >
  Card2( iRecordStream< Char >& is )
    try:
      matd( argument::extract< RECONR::Card3::Mat >( is ) ),
      ntemp( argument::extract< PURR::Card2::Ntemp >( is ) ),
      nsigz( argument::extract< PURR::Card2::Nsigz >( is ) ),
      iprint( argument::extract< Iprint >( is ) )
      { 
  Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 2" );
      throw e;
    }
};
