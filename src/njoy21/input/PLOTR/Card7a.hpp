class Card7a {
public:
//  #include "njoy21/input/PLOTR/Card3/Title.hpp"
  using Rl = PLOTR::Card3::Title;

  Argument< Rl > rl;

  template< typename Char >
  Card7a( iRecordStream< Char >& is )
    try:
      rl( argument::extract< Rl >( is ) )
    {
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 7a - Label for the secondary\n"
                "y-axis or the z-axis.");
      throw e;
    }
};
