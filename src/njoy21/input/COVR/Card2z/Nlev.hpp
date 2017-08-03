struct Nlev {
  using Value_t = int;
  
  static std::string name(){ return "nlev"; }
  static std::string description(){ 
    return
      "nlev defines the number of correlation matrix intervals to be used\n"
      "with Card2's icolor option.\n"
      "\n"
      "nlev must be an integer between 1 and 9, inclusively. nlev has a \n"
      "default value of 0.";
  } 
  
  static Value_t defaultValue() { return std::nullopt; }

  static bool verify( const Value_t& nlev ){
    return 0 < nlev and nlev < 10;
  }
};
