struct Nsigz {
  using Value_t = int;
  static std::string name(){ return "nsigz"; }

  static std::string description(){
    return
        "The nsigz argument specifies the number of sigma zero values desired\n"
        "for the production of the unresolved resonance tables. This argument\n"
        "defaults to a value of 1 and must be a positive integer (obviously).";
  }

  static int defaultValue(){ return 1; }
  static bool verify( Value_t n ){ return n > 0; }
};
