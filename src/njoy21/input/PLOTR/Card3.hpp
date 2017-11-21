class Card3 {
public:
  #include "njoy21/input/PLOTR/Card3/Title.hpp"
  using T1 = Title< hana::string<'t', '1'> >;

  Argument< T1 > t1;

  template< typename Char >
  Card3( iRecordStream< Char >& is )
    try:
      t1( argument::extract< T1 >( is ) )
    {
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 3 - Title line 1");
      throw e;
    }
};
