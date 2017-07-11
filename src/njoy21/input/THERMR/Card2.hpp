class Card2 {
public:
  #include "njoy21/input/THERMR/Card2/Matde.hpp"
  #include "njoy21/input/THERMR/Card2/Matdp.hpp"
  #include "njoy21/input/THERMR/Card2/Nbin.hpp"
  #include "njoy21/input/THERMR/Card2/Ntemp.hpp"
  #include "njoy21/input/THERMR/Card2/Iin.hpp"
  #include "njoy21/input/THERMR/Card2/Icoh.hpp"
  #include "njoy21/input/THERMR/Card2/Iform.hpp"
  #include "njoy21/input/THERMR/Card2/Natom.hpp"
  #include "njoy21/input/THERMR/Card2/Mtref.hpp"
  #include "njoy21/input/THERMR/Card2/Iprint.hpp"
  
  Argument< Matde > matde;
  Argument< Matdp > matdp;
  Argument< Nbin > nbin;
  Argument< Ntemp > ntemp;
  Argument< Iin > iin;
  Argument< Icoh > icoh;
  Argument< Iform > iform;
  Argument< Natom > natom;
  Argument< Mtref > mtref;
  Argument< Iprint > iprint;

  template< typename Char >
  Card2( iRecordStream< Char >& is, Argument< THERMR::Card1::Nendf >& nendf )
    try:
      matde ( argument::extract< Matde  >( is, nendf ) ),
      matdp ( argument::extract< Matdp  >( is ) ),
      nbin  ( argument::extract< Nbin   >( is ) ),
      ntemp ( argument::extract< Ntemp  >( is ) ),
      iin   ( argument::extract< Iin    >( is, nendf ) ),
      icoh  ( argument::extract< Icoh   >( is ) ),
      iform ( argument::extract< Iform  >( is ) ),
      natom ( argument::extract< Natom  >( is ) ),
      mtref ( argument::extract< Mtref  >( is ) ),
      iprint( argument::extract< Iprint >( is ) ){
	Card::clear(is);
    } catch( std::exception& e ){
      Log::info("Trouble while validating THERMR Card 2");
      throw e;
    }
};
