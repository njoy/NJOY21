struct Mtn {
  using Value_t = int;
  static std::string name(){ return "mtn"; }
  static std::string description(){
    return "The mtn parameter specifies the mt number for the output\n"
           "reactions.";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t mtn ){
    return ( mtn > 0 and mtn < 1000 );
  }
};
