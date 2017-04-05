struct Iwt {
  using Value_t = int;
  static std::string name(){ return "iwt"; }

  static std::string description() {
    return 
        "The iwt argument specifies the weighting patter as described in the\n"
        "NJOY manual. The different options are:\n"
        " - 0 = variable (default), \n"
        " - 1 = constant, are\n"
        " - 2 = tabulated.";
  }

  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t& iwt ){
    return ( iwt == 0 ) or ( iwt == 1) or ( iwt == 2 );
  }
};
