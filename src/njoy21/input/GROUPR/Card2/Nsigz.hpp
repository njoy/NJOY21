struct Nsigz {
  using Value_t = int;
  static std::string name(){ return "nsigz"; }
  static std::string description(){
    return
      "The nsigz argument specifies the number sigma zeros.\n"
      "\n"
      "The sigma zero values are given on Card5.";
  }

  static int defaultValue(){ return 1; }
  static bool verify( Value_t v ){ return v > 0; }
};
