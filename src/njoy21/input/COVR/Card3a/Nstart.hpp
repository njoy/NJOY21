struct Nstart {
  using Value_t = int;
  
  static std::string name(){ return "nstart"; }
  static std::string description(){ 
    return
      "The nstart input is the sequential figure number. If nstart is greater\n"
      "than 0, then plot are assigned a sequential number (beginning at\n"
      "nstart), and a list of figures is drawn on the final plot frame.\n"
      "\n"
      "If the nstart option is not desired, then a value of 0 is used to\n"
      "disable the sequential numbering. nstart has a default value of 1.";
  } 
  
  static Value_t defaultValue( ){ return 1; }
  
  static bool verify( const Value_t n ){ return n >= 0; }
};
