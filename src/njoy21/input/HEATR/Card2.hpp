class Card2 {
  public:
  using Matd = argument::common::Matd;
  #include "njoy21/input/HEATR/Card2/Npk.hpp"
  #include "njoy21/input/HEATR/Card2/Nqa.hpp"
  #include "njoy21/input/HEATR/Card2/Ntemp.hpp"
  #include "njoy21/input/HEATR/Card2/Local.hpp"
  #include "njoy21/input/HEATR/Card2/Iprint.hpp"
  #include "njoy21/input/HEATR/Card2/Ed.hpp"

  Argument< Matd   > matd;
  Argument< Npk    > npk;
  Argument< Nqa    > nqa;
  Argument< Ntemp  > ntemp;
  Argument< Local  > local;
  Argument< Iprint > iprint;
  Argument< Ed     > ed;

  template< typename Char >
  Card2( iRecordStream<Char>& is, Argument< HEATR::Card1::Nplot>& nplot )
  try:
    matd  ( argument::extract< Matd  >( is ) ),
    npk   ( argument::extract< Npk   >( is ) ),
    nqa   ( argument::extract< Nqa   >( is ) ),
    ntemp ( argument::extract< Ntemp >( is ) ),
    local ( argument::extract< Local >( is ) ),
    iprint( argument::extract< Iprint>( is, nplot ) ),
    ed    ( argument::extract< Ed    >( is, this->matd ) ){
      
      if ( iprint.value == 2 ){
        // Consistency with heatr.f90 would have
        // if ( npk.value * 3 + 7 > 28 ){
        if ( npk.value > 7 ){
          Log::info( "iprint value of 2, signifying kinematic check" );
          Log::info( "for kinematic checks, 6 partial kerma mt values (in\n"
                     "addition to mt = 301) are allowed" );
          Log::info( "number of kerma mts requested (npk): {}", npk.value );
          throw( "invalid npk input - requested too many kerma mts" );
        }
        // Consistency with heatr.f90 would have
        // else if ( npk.value + 3 > 28 ){
        else if ( npk.value > 25 ){
        Log::info( "iprint value of {}", iprint.value );
        Log::info( "for heatr runs that are not kinematic checks (where\n"
                   "iprint = 2), 25 partial kerma mt values (in addition\n"
                   "to mt = 301) are allowed" );
        Log::info( "number of kerma mts requested (npk): {}", npk.value );
        } 
      }
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble while validating HEATR Card2" );
    throw e;
  }
};
