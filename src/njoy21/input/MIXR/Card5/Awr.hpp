struct Awr {
  using Value_t = double;
  static std::string name(){ return "awr"; }
  static std::string description(){
    return
      "The awr argument specifies that atomic weight ratio, and is\n"
      "the mass ratio to the neutron for the mixture.";
  }
  static bool verify( const Value_t& a ){ return a > 0; }
};
