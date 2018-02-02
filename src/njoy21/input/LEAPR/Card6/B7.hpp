struct B7 {
  using Value_t = int;
  static std::string name(){ return "b7"; }
  static std::string description(){
    return
      "The b7 argument is the secondary scatterer type, and accepts a value\n"
      "of either 0, 1, or 2. The treatment of molecular moderators is\n"
      "determined by b7. A value of 0 corresponds to scattering only,\n"
      "which is appropriate for mixed moderators like BeO or Benzine. A\n"
      "value of 1 corresponds to free gas, and a value of 2 corresponds to\n"
      "diffusion.";
  }
  static bool verify( const Value_t& n ){ return n == 0 or n == 1 or n == 2; }
};
