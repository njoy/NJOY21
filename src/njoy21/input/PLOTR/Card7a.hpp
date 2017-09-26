class Card7a {
public:
  #include "njoy21/input/PLOTR/Card3/Title.hpp"

  Argument< Title > title;

  template< typename Char >
  Card7a( iRecordStream< Char >& is )
    try:
      title( argument::extract< Title >( is ) )
    {
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 7a - Label for the secondary\n"
                "y-axis or the z-axis.");
      throw e;
    }
};
