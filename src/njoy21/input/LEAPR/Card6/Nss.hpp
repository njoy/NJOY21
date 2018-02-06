struct Nss {
  using Value_t = int;
  static std::string name(){ return "nss"; }
  static std::string description(){
    return
      "The nss argument is the number of secondary scatterers, and can equal\n"
      "either 0 or 1. If nss equals zero, then all subseqent Card6 entries\n"
      "are invalid, and Card6 would correctly be '0/'. If nss is not equal to\n"
      "zero, then all subseqent cards are necessary.";
  }
  static bool verify( const Value_t& n ){ return n == 0 or n == 1; }
};
