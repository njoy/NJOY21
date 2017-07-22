struct Icoh {
  using Value_t = int;
  static std::string name(){ return "icoh"; }

  static std::string description(){
    return
      "icoh is the elastic scattering option, where a value of 0 indicates\n"
      "that no elastic scattering will be considered, while a value of 1\n"
      "indicates that elastic scattering will be computed using ENDF6 format\n"
      "data.\n"
      "\n"
      "For earlier formats, a value of 1 corresponds to graphite, 2 to\n"
      "beryllium, 3 to beryllium oxide, 11 to polyethylene, 12 to h(zrh),\n"
      "and 13 to zr(zrh).\n";
  }

  static bool verify( Value_t i ){ 
    return ( 0 <= i and i <= 3 ) or ( 11 <= i and i <= 13 );
  }
};

