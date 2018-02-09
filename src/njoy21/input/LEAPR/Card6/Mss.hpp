struct Mss {
  using Value_t = int;
  static std::string name(){ return "mss"; }
  static std::string description(){
    return
      "The mss argument is the number of secondary scattering atoms in a\n"
      "compound. In other words, if a secondary scatterer is identified,\n"
      "then mss is the number of times this atom occurs in a compound.\n"
      "\n"
      "mss must be a positive interger.";
  }
  static bool verify( const Value_t& mss ){ return mss > 0; }
};
