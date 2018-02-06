struct Spr {
  using Value_t = Quantity<Barns>;
  static std::string name(){ return "spr"; }
  static std::string description(){
    return
      "The spr input is the free atom cross section for the principal\n"
      "scatterer. The value of spr should be chosen using the principal\n"
      "scatterer's neutron file. In the ENDF file, find the section for\n"
      "elastic scattering (MF=3, MT=2), and select the cross section value\n"
      "that corresponds with the minimum energy value.\n"
      "\n"
      "spr must be positive, and provided in units of barns.";
  }
  static bool verify( const Value_t& spr ){ 
    return spr > ( 0 * dimwits::barns ); 
  }
};
