struct Ntemp {
  using Value_t = int;
  static std::string name(){ return "ntemp"; }
  static std::string description(){
    return
      "The ntemp argument specifies the number of final temperatures\n"
      "desired. These temperatures will be put on card3. ntemp defaults\n"
      "to a value of 1 and must be a positive integer";
  }

  static Value_t defaultValue(){ return 1; }
  static bool verify( const Value_t& v ){ return v > 0; }
};
