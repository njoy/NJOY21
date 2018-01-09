struct Mti{
  using Value_t = double;
  static std::string name(){ return "mti"; }
  static std::string description(){
    return "The mti parameter specifies the thermal inelastic mt.";
  }
  static bool verify( const Value_t mti ){
    return mti >= 0.0;
  }
};
