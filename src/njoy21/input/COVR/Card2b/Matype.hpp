struct Matype {
  using Value_t = int;
  
  static std::string name(){ return "matype"; }
  static std::string description(){ 
    return
      "The matype input indicates the output library matrix type, given that\n"
      "the library option was the selected for the output form. The matrix\n"
      "can either be in terms of covariances or correlation coefficients. A\n"
      "value of 3 corresponds to covariances, while a value of 4 corresponds\n"
      "to correlation coefficients.\n"
      "\n"
      "matype has a default value of 3.";
  } 
  
  static Value_t defaultValue(){ return 3; }
  
  static bool verify( const Value_t i ){ return i == 3 or i == 4; }
};
