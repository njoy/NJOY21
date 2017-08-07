struct Ndiv {
  using Value_t = int;
  
  static std::string name(){ return "ndiv"; }
  static std::string description(){ 
    return
      "The ndiv input is the number of subdivisions for each of the gray\n"
      "shades. One gray-shade step equals 0.20 in correlation magnitude if\n"
      "ndiv=1. Finer gradations are possible with ndiv greater than 1.\n"
      "\n"
      "ndiv must be a positive integer, and has a default value of 1.";
  } 
  
  static Value_t defaultValue( ){ return 1; }
  
  static bool verify( const Value_t n ){ return n > 0; }
};
