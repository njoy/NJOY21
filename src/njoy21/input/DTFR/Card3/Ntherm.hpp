struct Ntherm {
  using Value_t = int;
  static std::string name(){ return "ntherm"; }

  static std::string description(){
    return
      "Ntherm is the number of incident thermal groups, and is used to\n"
      "define the breakpoint between the thermal and epithermal treatments.\n"
      "If no thermal upscatter cross sections are desired, ntherm can be \n"
      "set equal to 0.";
 }

  static Value_t defaultValue( ){ return 0; }
  static bool verify( Value_t i ){ return 0 <= i; } 
};

