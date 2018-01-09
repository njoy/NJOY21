struct If4{
  using Value_t = int;
  static std::string name(){ return "if4"; }
  static std::string description(){
    return "The if4 parameter specifies whether or not to process the file4\n"
           "cross section data.\n"
           " 0 = do not process\n"
           " 1 = process (default)";
  }
  static Value_t defaultValue(){ return 1; }
  static bool verify( const Value_t if4 ){
    return ( if4 == 0 or if4 == 1 );
  }
};
