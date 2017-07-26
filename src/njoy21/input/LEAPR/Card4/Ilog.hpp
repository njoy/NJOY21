struct Ilog { 
  using Value_t = int;
  static std::string name(){ return "ilog"; } 
  static std::string description(){
    return 
      "The ilog input is the log flag, which is used to control whether the\n"
      "output file contains S or log10(S). The latter option is the ENDF\n"
      "sanctioned way of handling very small numbers in File 7.\n"
      "\n"
      "A value of 0 indicates that S will be used, while a value of 1\n"
      "indicates that log10(S) will be used.\n"
      "\n"
      "ilog has a default value of 0.";
  }

  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t i ){
    return ( i == 0 or i == 1 );
  }
};
