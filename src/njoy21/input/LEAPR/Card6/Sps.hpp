struct Sps {
  using Value_t = Quantity<Barns>;
  static std::string name(){ return "sps"; }
  static std::string description(){
    return
      "The sps input is the free atom cross section for the secondary\n"
      "scatterer. The value of sps should be chosen using the secondary\n"
      "scatterer's neutron file. In the ENDF file, find the section for\n"
      "elastic scattering (MF=3, MT=2), and select the cross section value\n"
      "that corresponds with the minimum energy value.\n"
      "\n"
      "sps must be positive, and provided in units of barns.";
  }
  static bool verify( const Value_t& sps ){ 
    return sps > ( 0 * dimwits::barns ); 
  }
};
