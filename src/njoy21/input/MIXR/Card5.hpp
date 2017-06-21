class Card5 {
  public:
    #include "njoy21/input/MIXR/Card5/Matd.hpp"
    #include "njoy21/input/MIXR/Card5/Za.hpp"
    #include "njoy21/input/MIXR/Card5/Awr.hpp"
    
    Argument< Matd > matd;
    Argument< Za > za;
    Argument< Awr > awr;
    
    template< typename Char >
    Card5( iRecordStream< Char >& is )
      try:
        matd( argument::extract< Matd >( is ) ),
	za( argument::extract< Za >( is ) ),
	awr( argument::extract< Awr >( is ) )
	{
          Card::clear( is );
	}
      catch( std::exception& e ){
        Log::info( "Trouble validating Card5" );
	throw e;
      }
};
