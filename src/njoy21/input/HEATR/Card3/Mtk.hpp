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
      "defined unless a gamm fail for the mt is on the endf tape.\n"
      "\n"
      "The mt values should not be comma separated.";
  }

  static bool verify( const Value_t& mtk, 
                      const Argument< HEATR::Card2::Npk >& ){
    for( int mt : mtk ){
      if( mt == 301 ){
        Log::info( "mt value of 301 is automatically provided" );
      }
      if( mt < 302 or mt > 450 ){
        Log::info( "mt value {} is out of range", mt );
	return false;
      }
    }
    return true;
  }    



/*  auto foundInvalid = std::find_if( mtk.begin(), mtk.end(), 
      []( auto& m ){ return m < 300; } );
    if ( foundInvalid != mtk.end() ){
      Log::info( "mt value ({}) found at index {} is out of range (302 - 450)",
        *foundInvalid, std::distance(mtk.begin(), foundInvalid));
      return false;
    }
    return true;
  }*/
};
