struct Irelco {
  using Value_t = int;
  
  static std::string name(){ return "irelco"; }
  static std::string description(){ 
    return
      "The irelco input indicates the type of covariances preset on nin.\n"
      "The irelco value  must match the value used in the ERRORR run that\n"
      "produced the covariances to be plotted.\n"
      "\n"
      "irelco accepts a value of either 0 or 1, which indicate absolute\n"
      "and relative covariances, respectively. irelco has a default value\n"
      "of 1.";
  } 
  
  static Value_t defaultValue( ){ return 1; }
  
  static bool verify( const Value_t i ){ return i == 0 or i == 1; }
};
