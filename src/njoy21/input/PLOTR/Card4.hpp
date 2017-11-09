class Card4 {
public:
  #include "njoy21/input/PLOTR/Card4/Itype.hpp"
  #include "njoy21/input/PLOTR/Card4/Jtype.hpp"
  #include "njoy21/input/PLOTR/Card4/Igrid.hpp"
  #include "njoy21/input/PLOTR/Card4/Ileg.hpp"
  #include "njoy21/input/PLOTR/Card4/Xtag.hpp"
  #include "njoy21/input/PLOTR/Card4/Ytag.hpp"

  Argument< Itype > itype;
  Argument< Jtype > jtype;
  Argument< Igrid > igrid;
  Argument< Ileg > ileg;
  Argument< Xtag > xtag;
  Argument< Ytag > ytag;

  template< typename Char >
  Card4 ( iRecordStream< Char >& is )
    try:
      itype( argument::extract< Itype >( is ) ),
      jtype( argument::extract< Jtype >( is ) ),
      igrid( argument::extract< Igrid >( is ) ),
      ileg( argument::extract< Ileg >( is ) ),
      xtag( argument::extract< Xtag >( is ) ),
      ytag( argument::extract< Ytag >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card4" );
      throw e;
    }
};
