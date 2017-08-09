class Card3c {
  public:
    #include "njoy21/input/COVR/Card3c/Hdescr.hpp"
          
    Argument< Hdescr > hdescr;

    template< typename Char >
    Card3c( iRecordStream<Char>& is )
    try:
      hdescr( argument::extract< Hdescr >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble while validating COVR Card3c" );
      throw e;
    }
};
