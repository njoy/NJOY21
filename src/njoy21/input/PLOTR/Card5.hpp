class Card5 {
public:
  #include "njoy21/input/PLOTR/Card5/El.hpp"
  #include "njoy21/input/PLOTR/Card5/Eh.hpp"
  #include "njoy21/input/PLOTR/Card5/Xstep.hpp"

  Argument< El > el;
  Argument< Eh > eh;
  Argument< Xstep > xstep;

  template< typename Char >
  Card5 ( iRecordStream< Char >& is,
          Argument< PLOTR::Card4::Xtag >& xtag,
          Argument< PLOTR::Card4::Itype >& itype,
          const int ileg )
    try:
      el( argument::extract< El >( is, itype.value ) ),
      eh( argument::extract< Eh >( is, this->el.value ) ),
      xstep( argument::extract< Xstep >( is, this->el.value, this->eh.value ) )
      {
        if( ileg != 0 and this->el.value != std::nullopt ){
          xtag.value = xtag.value.value_or( *( this->el.value ) );
        }
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating PLOTR Card5" );
      throw e;
    }
};
