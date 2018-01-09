struct Decay{
  using Value_t = double;
  static std::string name(){ return "decay"; }
  static std::string description(){
    return "The decay parameter specifies the decay constant for this\n"
           "time-dependent isotope. The default value is 0.0.";
  }
  static Value_t defaultValue(){ return 0.0; }
  static bool verify( const Value_t decay ){
    return decay >= 0.0;
  }
};
