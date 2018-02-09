class Card2 {
  public:
    #include "njoy21/input/COVR/Card2/Icolor.hpp"
	  
    Argument< Icolor > icolor;

    template< typename Char >
    Card2( iRecordStream<Char>& is )
    try:
      icolor ( argument::extract< Icolor >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble while validating COVR Card2" );
      throw e;
    }
};
