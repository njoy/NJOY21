class Card2z {
  public:
    #include "njoy21/input/COVR/Card2z/Nlev.hpp"
    #include "njoy21/input/COVR/Card2z/Tlev.hpp"
	  
    Argument< Nlev > nlev;
    Argument< Tlev > tlev;

    template< typename Char >
    Card2z( iRecordStream<Char>& is )
    try:
      nlev ( argument::extract< Nlev >( is ) ),
      tlev ( argument::extract< Tlev >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble while validating COVR Card2z" );
      throw e;
    }
};
