class Card1 {
  public:
    using Nin = argument::common::Nin;
    #include "njoy21/input/COVR/Card1/Nout.hpp"
    #include "njoy21/input/COVR/Card1/Nplot.hpp"
    
    Argument< Nin > nin;
    Argument< Nout > nout;
    Argument< Nplot > nplot;

    template< typename Char >
    Card1( iRecordStream<Char>& is )
    try:
      nin  ( argument::extract< Nin   >( is ) ), 
      nout ( argument::extract< Nout  >( is, this->nin ) ), 
      nplot( argument::extract< Nplot >( is, this->nin, this->nout ) )
      {
        if( nout.value == 0 and nplot.value == 0 ){
          Log::info( "Both nout and nplot are set to zero, meaning that\n"
                     "no output format is chosen." );
	  throw( "Invalid output format selected" );
	}
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble while validating HEATR Card2" );
      throw e;
    }
};
