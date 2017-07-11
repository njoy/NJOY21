struct Ipingp {
  using Value_t = int;
  static std::string name(){ return "ipingp"; }

  static std::string description(){
    return
      "Ipingp is the position of the in-group scattering cross section, and\n"
      "is equal to iptotl + nup + 1, where nup is the total number of \n"
      "upscatter groups (note that nup is not an input, since it can be \n"
      "deduced from iptotl and ipingp).";
  }

  static bool verify( Value_t i, const Argument< Card3::Iptotl >& iptotl ){ 
    return iptotl.value + 1 <= i; 
  } 
};

