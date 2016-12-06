struct Nladr {
  using Value_t = int;
  static std::string name(){ return "nladr"; }

  static std::string description(){
    return
        "The nbin argument specifies the number of probability bins used in \n"
        "the production of the unresolved resonance tables. This argument\n"
        "defaults to a value of 20 and must be greater than 14.";
  }

  static int defaultValue(){ return 64; }
  static bool verify( Value_t n ){ return n > 0; }
};

