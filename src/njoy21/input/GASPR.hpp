class GASPR {
public:
  /* nested types */
  #include "njoy21/input/GASPR/Card1.hpp"
  
  /* fields */
  Card1 card1;

  /* ctor */
  template< typename Char >
  GASPR( iRecordStream<Char>& is )
    try : card1( is ){} catch( std::exception& e ) {
      Log::info("Trouble while validating GASPR input");
      throw e;
    }
};
