class Card2 {
public:

  #include "njoy21/input/WIMSR/Card2/Iprint.hpp"
  #include "njoy21/input/WIMSR/Card2/Iverw.hpp"
  #include "njoy21/input/WIMSR/Card2/Igroup.hpp"

  Argument< Iprint > iprint;
  Argument< Iverw > iverw;
  Argument< Igroup > igroup;

  template< typename Istream >
  Card2( iRecordStream< Istream >& is )
  try:
    iprint( argument::extract< WIMSR::Card2::Iprint >( is ) ),
    iverw( argument::extract< WIMSR::Card2::Iverw >( is ) ),
    igroup( argument::extract< WIMSR::Card2::Igroup >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card2." );
    throw e;
  }
};
