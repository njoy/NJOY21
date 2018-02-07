struct If5{
  using Value_t = int;
  static std::string name(){ return "if5"; }
  static std::string description(){
    return "The if5 parameter specifies what should be done with the file5\n"
           "burnup data.\n"
           " 0 = do not process file 5 burnup data (default)\n"
           " 1 = process burnup data along with the rest of the data\n"
           " 2 = process burnup data only";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t if5 ){
    return ( if5 == 0 or if5 == 1 or if5 == 2 );
  }
};
