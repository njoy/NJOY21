struct Ntempr {
  using Value_t = int;
  static std::string name(){ return "ntempr"; }
  static std::string description(){
    return
      "The ntempr argument specifies the number of final temperatures\n"
      "desired. For each temperature value, cards 10 - 18 will be repeated,\n"
      "with the desired temperature specified on card10.\n"
      "ntempr defaults to a value of 1 and must be a positive integer";
  }

  static Value_t defaultValue(){ return 1; }
  static bool verify( const Value_t& v ){ return v > 0; }
};
