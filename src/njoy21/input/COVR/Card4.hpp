class Card4 {
  public:
    #include "njoy21/input/COVR/Card4/Mat.hpp"
    #include "njoy21/input/COVR/Card4/Mt.hpp"
    #include "njoy21/input/COVR/Card4/Mat1.hpp"
    #include "njoy21/input/COVR/Card4/Mt1.hpp"
	  
    Argument< Mat  > mat;
    Argument< Mt   > mt;
    Argument< Mat1 > mat1;
    Argument< Mt1  > mt1;

    template< typename Char >
    Card4( iRecordStream<Char>& is )
    try:
      mat  ( argument::extract< Mat  >( is ) ),
      mt   ( argument::extract< Mt   >( is ) ),
      mat1 ( argument::extract< Mat1 >( is ) ),
      mt1  ( argument::extract< Mt1  >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble while validating COVR Card4" );
      throw e;
    }
};
