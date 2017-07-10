struct Iprint {
  using Value_t = int;
  static std::string name(){ return "iprint"; }

  static std::string description(){
    return
        "The iprint argument specifies the verbosity of the printed output. \n"
        "A value 0 produces the minimum amount of ouput (i.e., quiet) while \n"
        "a value of 1 produces the maximum.";
  }

  static Value_t defaultValue(){ return 1; }
  static bool verify( Value_t i ){ return ( i == 0 ) or ( i == 1 ); }
};

