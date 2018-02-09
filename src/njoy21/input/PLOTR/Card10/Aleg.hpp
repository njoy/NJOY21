struct Aleg {
  using Value_t = std::string;
  static std::string name(){ return "aleg"; }
  static std::string description(){
    return
      "The aleg parameter is the title for the curve tag or legend block.\n"
      "60 characters max.  The default is a blank string.";
  }

  static Value_t defaultValue(){ return ""; }
  static bool verify( const Value_t& s ){ return s.length() < 61; }
};
