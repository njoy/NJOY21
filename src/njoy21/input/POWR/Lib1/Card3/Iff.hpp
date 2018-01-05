struct Iff{
  using Value_t = int;
  static std::string name(){ return "iff"; }
  static std::string description(){
    return "The iff parameter specifies the f-factor option.\n\n"
           " 0 = do not calculate f-factors\n"
           " 1 = calculate the f-factors if they are found (default)";
  }
  static Value_t defaultValue(){ return 1; }
  static bool verify( const Value_t iff ){
    return ( iff == 0 or iff == 1 );
  }
};
