struct Ncase {
  using Value_t = int;
  
  static std::string name(){ return "ncase"; }
  static std::string description(){ 
    return
      "The ncase input indicates the number of cases (i.e. occurrences of \n"
      "card4) to be run.\n"
      "\n"
      "ncase accepts an integer input between 1 and 60, inclusively. ncase\n"
      "has a default value of 1.";
  } 
  
  static Value_t defaultValue( ){ return 1; }
  
  static bool verify( const Value_t n ){ return n > 0 and n < 61; }
};
