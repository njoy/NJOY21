class MODER {
public:
  /* nested types */
  #include "njoy21/input/MODER/Card1.hpp"
  #include "njoy21/input/MODER/Card2.hpp"
  #include "njoy21/input/MODER/Card3.hpp"

  /* fields */
  Card1 card1;
  optional< Card2 > card2;
  optional< std::vector< Card3 > > card3List;

  /* ctor */
  template< typename Char >
  MODER( iRecordStream<Char>& is )
    try :
      card1( is  ){
        if ( std::abs( this->card1.nin.value ) < 4 ){
          this->card2 = Card2( is );
          this->card3List = std::vector<Card3>();
          card3List->emplace_back( is, this->card1.nout );
          if ( not card3List->back().nin.value ){
            Log::error
              ("Zero input tape / material identification pairs specified");
            Log::info(
              "\nWhen MODER is operating in aggregation mode (i.e. the MODER\n"
              "card 1 nin argument is 1, 2, or 3), input is required to provide\n"
              "two or more MODER card3 entries. For all but the last card3 entry,\n"
              "the card specifies a input tape and material identification\n"
              "(i.e MAT number) pair. The last card 3 entry, specifies an\n"
              "tape value of zero and defaults the material identification\n"
              "(using a '/'), which signal the end of the MODER card 3 entry\n"
              "sequence.");
            throw std::exception();
          }
          while ( card3List->back().nin.value ){
            card3List->emplace_back( is, this->card1.nout );
          }
          card3List->pop_back();
        }
    } catch( std::exception& e ){
      Log::info("Trouble while validating MODER input");
      throw e;
    }
};
