struct Isabt { 
  using Value_t = int;
  static std::string name(){ return "isabt"; } 
  static std::string description(){
    return 
      "The isabt input controls whether the ouput ENDF tape contains the\n"
      "symmetric S(a,b), or the asymmetric S(a,b). The asymmetric option\n"
      "gives better numberics, but is not sanctioned by the ENDF-6 format.\n"
      "\n"
      "An isabt value of 0 corresponds to a symmetric S(a,b), while a value\n"
      "of 1 corresponds to an asymmetric S(a,b).\n"
      "\n"
      "isabt has a default value of 0.";
  }

  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t i ){ return ( i == 0 or i == 1 ); }
};
