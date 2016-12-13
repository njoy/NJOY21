struct Itype {
  using Value_t = int;
  static std::string name(){ return "itype"; }

  static std::string description(){
    return
        "The itype argument parameter specifies whether the output library\n"
        "will be in ASCII (itype=1) or binary (itype=2).";
  }

  static Value_t defaultValue(){ return 1; }
  static bool verify( Value_t i ){ return ( i == 1 ) or ( i == 2 ); }
};
