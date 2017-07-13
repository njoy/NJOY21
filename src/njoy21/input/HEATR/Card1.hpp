class Card1{
  public:
  #include "njoy21/input/HEATR/Card1/Nendf.hpp"
  #include "njoy21/input/HEATR/Card1/Nin.hpp"
  #include "njoy21/input/HEATR/Card1/Nout.hpp"
  #include "njoy21/input/HEATR/Card1/Nplot.hpp"

  Argument< Nendf > nendf;
  Argument< Nin > nin;
  Argument< Nout > nout;
  Argument< Nplot > nplot;

  template< typename Char >
  Card1( iRecordStream<Char>& is )
    try:
      nendf( argument::extract< Nendf >( is ) ),
      nin( argument::extract< Nin >( is, this->nendf ) ),
      nout( argument::extract< Nout >( is, this->nendf, this->nin ) ),
      nplot( argument::extract< Nplot >( is, this->nendf, this->nin, this->nout ) ){
	Card::clear(is);
    } catch( std::exception& e ){
      Log::info("Trouble while validating HEATR Card 1");
      throw e;
    }
};
