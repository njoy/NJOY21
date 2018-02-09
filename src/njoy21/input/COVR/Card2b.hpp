class Card2b {
  public:
    #include "njoy21/input/COVR/Card2b/Matype.hpp"
    #include "njoy21/input/COVR/Card2b/Ncase.hpp"
          
    Argument< Matype > matype;
    Argument< Ncase > ncase;

    template< typename Char >
    Card2b( iRecordStream<Char>& is )
    try:
      matype ( argument::extract< Matype >( is ) ),
      ncase( argument::extract< Ncase >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble while validating COVR Card2b" );
      throw e;
    }
};
