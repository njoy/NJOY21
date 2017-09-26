class Card5 {
public:
  #include "njoy21/input/PLOTR/Card5/El.hpp"
  #include "njoy21/input/PLOTR/Card5/Eh.hpp"
  #include "njoy21/input/PLOTR/Card5/Xstep.hpp"

  Argument< El > el;
  Argument< Eh > eh;
  Argument< Xstep > xstep;

  template< typename Char >
  Card5 ( iRecordStream< Char >& is )
    try:
      el( argument::extract< El >( is, card4 ) ),
      eh( argument::extract< Eh >( is, this->el ) ),
      xstep( argument::extract< Xstep >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating PLOTR Card5" );
      throw e;
    }
};
