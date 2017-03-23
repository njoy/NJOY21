class Card2 {
public:
  #include "njoy21/input/ACER/Card2/Iopt.hpp"
  #include "njoy21/input/ACER/Card2/Iprint.hpp"
  #include "njoy21/input/ACER/Card2/Itype.hpp"
  #include "njoy21/input/ACER/Card2/Suff.hpp"
  #include "njoy21/input/ACER/Card2/Nxtra.hpp"

  Argument< Iopt > iopt;
  Argument< Iprint > iprint;
  Argument< Itype > itype;
  Argument< Suff > suff;
  Argument< Nxtra > nxtra;

  template< typename Char >
  Card2( iRecordStream< Char >& is )
    try:
      iopt( argument::extract< Iopt >( is ) ),
      iprint( argument::extract< Iprint >( is ) ),
      itype( argument::extract< Itype >( is ) ),
      suff( argument::extract< Suff >( is ) ),
      nxtra( argument::extract< Nxtra >( is ) )
    {   
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card2");
      throw e;
    }
};
