class Card2 {
public:
  #include "njoy21/input/GROUPR/Card2/Matb.hpp"
  #include "njoy21/input/GROUPR/Card2/Ign.hpp"
  #include "njoy21/input/GROUPR/Card2/Igg.hpp"
  #include "njoy21/input/GROUPR/Card2/Iwt.hpp"
  #include "njoy21/input/GROUPR/Card2/Lord.hpp"
  #include "njoy21/input/GROUPR/Card2/Ntemp.hpp"
  #include "njoy21/input/GROUPR/Card2/Nsigz.hpp"
  #include "njoy21/input/GROUPR/Card2/Iprint.hpp"
  #include "njoy21/input/GROUPR/Card2/Ismooth.hpp"

  Argument< Matb > matb;
  Argument< Ign > ign;
  Argument< Igg > igg;
  Argument< Iwt > iwt;
  Argument< Lord > lord;
  Argument< Ntemp > ntemp;
  Argument< Nsigz > nsigz;
  Argument< Iprint > iprint;
  Argument< Ismooth > ismooth;

  template< typename Char >
  Card2( iRecordStream< Char >& is )
    try:
      matb( argument::extract< Matb >( is ) ),
      ign( argument::extract< Ign >( is ) ),
      igg( argument::extract< Igg >( is ) ),
      iwt( argument::extract< Iwt >( is ) ),
      lord( argument::extract< Lord >( is ) ),
      ntemp( argument::extract< Ntemp >( is ) ),
      nsigz( argument::extract< Nsigz >( is ) ),
      iprint( argument::extract< Iprint >( is ) ),
      ismooth( argument::extract< Ismooth >( is ) )
    {   
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card2");
      throw e;
    }
};
