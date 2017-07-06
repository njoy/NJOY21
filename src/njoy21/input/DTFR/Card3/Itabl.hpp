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
      "Thus, itabl must always be greater than or equal to iptotl + ng."; 
  }

  static bool verify( const Value_t i,
                      const Argument<DTFR::Card3::Iptotl>& iptotl,
                      const Argument<DTFR::Card3::Ng>& ng ){ 
    return ( iptotl.value + ng.value ) <= i; 
  } 
};

