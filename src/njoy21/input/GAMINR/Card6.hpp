class Card6 {
public:
  #include "njoy21/input/GAMINR/Card6/Mfd.hpp"
  using Mtd = GROUPR::Card9::Mtd;
  #include "njoy21/input/GAMINR/Card6/Mtname.hpp"

  #include "njoy21/input/GAMINR/Card6/src/readRest.hpp"

 Argument< Mfd > mfd;
 optional< std::pair< Argument< Mtd >, Argument< Mtname > > > rest;
// Argument< Mtd > mtd;
// Argument< Mtname > mtname;

  template< typename Char >
  Card6( iRecordStream< Char >& is )
    try:
      mfd( argument::extract< Mfd >( is ) ),
      rest( readRest( is, this->mfd.value ) )
//      mtd( argument::extract< Mtd >( is ) ),
//      mtname( argument::extract< Mtname >( is, this->mfd ) )
    {   
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card6");
      throw e;
    }
};
