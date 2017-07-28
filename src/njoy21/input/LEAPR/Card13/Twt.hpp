struct Twt {
  using Value_t = double;
  static std::string name(){ return "twt"; }
  static std::string description(){
    return
      "The twt argument is the translational weight for the continuous\n"
      "distribution. If no translational modes are desired, twt should\n"
      "be set to 0.0. Else, twt must be positive.";
  }
  static bool verify( const Value_t& twt ){ return twt >= 0.0; }
};
