struct Matde : argument::common::Matd {
  static std::string name(){ return "matde"; }
  static std::string description(){
    return
      "The matde input is the material id for the desired material on the\n"
      "endf tape, which was specified on the card1 input parameter 'nendf'.\n"
      "\n"
      "Material id numbers must be positive integers with values less than\n"
      "10,000. For the matde input in particular, however, a value of 0 is\n"
      "valid, as that signifies that no nendf tape was provided.";
  }
  static bool verify( const Value_t& i, 
                      const Argument< THERMR::Card1::Nendf >& nendf ){
    if( nendf.value == 0 and i != 0 ){ 
      Log::info( "No endf input provided (nendf = 0), so matde must = 0");
      return false;
    }
    if( nendf.value != 0 and i == 0 ){
      Log::info( "endf input provided (nendf != 0), so matde must be > 0");
      return false;
    }
    
    return argument::common::Matd::verify( i ) or i == 0;
  }
};
