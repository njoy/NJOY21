struct Mti {
  using Value_t = int;
  static std::string name(){ return "mti"; }
  static std::string description(){
    return "The mti parameter specifies the thermal inelastic mt.\n"
           "The default value is zero (0), specifying none.";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t mti ){
    return mti >= 0;
  }
};
