class Card9 {
public:
  #include "njoy21/input/GROUPR/Card9/Mfd.hpp"
  #include "njoy21/input/GROUPR/Card9/Mtd.hpp"
  #include "njoy21/input/GROUPR/Card9/Mtname.hpp"

 Argument< Mfd > mfd;
 Argument< Mtd > mtd;
 Argument< Mtname > mtname;

  template< typename Char >
  Card9( iRecordStream< Char >& is )
    try:
      mfd( argument::extract< Mfd >( is ) ),
      mtd( argument::extract< Mtd >( is ) ),
      mtname( argument::extract< Mtname >( is , mfd ) )
    {   
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card9");
      throw e;
    }
};
