struct Mtk {
  using Value_t = std::vector<int>;
  static std::string name(){ return "mtk"; }
  static std::string description(){
    return
      "mtk is a set of mt numbers for partial kermas. The card2 input npk\n"
      "indicates how many mt numbers are to be provided in the mtk input.\n"
      "The mt = 301 kerma (total cross section) is automatically provided,\n"
      "so it does not need to be input. Therefore, mt partial kerma inputs\n"
      "are valid if they lie within the range of 302 and 450, inclusively.\n"
      "\n"
      "The partial kerma mt for a given reaction is (mt + 300), i.e. the mt\n"
      "for total cross section is 1, therefore its corresponding partial\n"
      "kerma mt value is 301. A given partial kerma mt may not be properly\n"
      "defined unless a gamm fail for the mt is on the endf tape.";
  }

  static bool verify( const Value_t& mtk, 
                      const Argument< HEATR::Card2::Npk >& ){
    bool foundInvalid = std::find_if( mtk.begin(), mtk.end(), 
      []( int& m ){ return ( m < 451 and m > 300 ); } );
  }
};
