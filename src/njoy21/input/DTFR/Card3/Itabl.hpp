struct Itabl {
  using Value_t = int;
  static std::string name(){ return "itabl"; }

  static std::string description(){
    return
      "Itabl is the length of the desired neutron table. The total length\n"
      "is calculated by the number of special edit positions at the front\n"
      "of the table (iptotl - 3), plus 3, plus the total number of\n"
      "upscatter groups (nup, which is not a DTFR input), plus the number\n"
      "of groups (ng, from previous GROUPR input).\n"
      "\n"
      "In total, itabl = (iptotl - 3) + 3 + nup + ng.\n"
      "\n"
      "Itabl must be an integer greater than zero."; 
  }

  static bool verify( Value_t i ){ return 0 < i; } 
};

