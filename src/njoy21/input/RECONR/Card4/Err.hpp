struct Err {
  using Value_t = double;
  static std::string name(){ return "err"; }

  static std::string description(){
    return 
      "The err argument specifies the fractional reconstruction tolerance \n"
      "used when resonance-integral error criterion *is not* satisfied.\n"
      "This value is required to be positive."
      "\n"
      "See also description for errint.";
  }

  static bool verify( const Value_t& e ){ return (e > 0.0); }
};
