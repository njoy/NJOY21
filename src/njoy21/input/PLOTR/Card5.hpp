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
          Argument< PLOTR::Card4 >& card4,
          Argument< PLOTR::Card4::Itype >& itype )
    try:
      el( argument::extract< El >( is, itype.value ) ),
      eh( argument::extract< Eh >( is, this->el.value ) ),
      xstep( argument::extract< Xstep >( is ) )
      {
        card4.xtag.value = card4.xtag.value_or( this->el.value );
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating PLOTR Card5" );
      throw e;
    }
};
