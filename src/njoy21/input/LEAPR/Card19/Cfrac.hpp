struct Cfrac {
  using Value_t = double;
  static std::string name(){ return "cfrac"; }
  static std::string description(){
    return
      "The cfrac argument gives the coherent scattering fraction for use with\n"
      "the Skold option for intermolecular interference at very low neutron\n"
      "energies. cfrac should be an entry between 0 and 1, inclusively.\n"
      "\n"
      "cfrac should only be used when nsk (card5 input) is equal to 2.";
  }
  static bool verify( const Value_t& cfrac ){ 
    return 0.0 <= cfrac and cfrac <= 1.0; 
  }
};
