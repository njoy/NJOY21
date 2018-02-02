struct Awr {
  using Value_t = double;
  static std::string name(){ return "awr"; }
  static std::string description(){
    return
      "The awr input is the weight ratio of the principal scatterer to\n"
      "neutron. awr is unitless, and must be positive.";
  }
  static bool verify( const Value_t& awr ){ return awr > ( 0.0 ); }
};
