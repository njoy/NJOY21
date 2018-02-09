class Card3b {
  public:
    #include "njoy21/input/COVR/Card3b/Hlibid.hpp"
          
    Argument< Hlibid > hlibid;

    template< typename Char >
    Card3b( iRecordStream<Char>& is )
    try:
      hlibid( argument::extract< Hlibid >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble while validating COVR Card3b" );
      throw e;
    }
};
