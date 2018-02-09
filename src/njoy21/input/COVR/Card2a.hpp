class Card2a {
  public:
    #include "njoy21/input/COVR/Card2a/Epmin.hpp"
	  
    Argument< Epmin > epmin;

    template< typename Char >
    Card2a( iRecordStream<Char>& is )
    try:
      epmin ( argument::extract< Epmin >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble while validating COVR Card2a" );
      throw e;
    }
};
