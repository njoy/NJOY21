class Card2 {
public:
  /* nested types */
  using Mat = RECONR::Card3::Mat;
  using Ntemp = PURR::Card2::Ntemp;
  using Nsigz = PURR::Card2::Nsigz;
  #include "njoy21/input/UNRESR/Card2/Iprint.hpp"

  Argument< Mat > matd;
  Argument< Ntemp > ntemp;
  Argument< Nsigz > nsigz;
  Argument< Iprint > iprint;

  template< typename Char >
  Card2( iRecordStream< Char >& is )
    try:
      matd( argument::extract< Mat >( is ) ),
      ntemp( argument::extract< Ntemp >( is ) ),
      nsigz( argument::extract< Nsigz >( is ) ),
      iprint( argument::extract< Iprint >( is ) ) { 
        Card::clear( is );
      } catch( std::exception& e ) {
        Log::info( "Trouble while validating card 2" );
        throw e;
      }
};
