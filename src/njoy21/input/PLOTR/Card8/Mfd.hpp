struct Mfd {
  using Value_t = optional< int >;
  static std::string name(){ return "mfd"; }
  static std::string description(){
    return 
        "The mfd parameter specifies the ENDF file to be used.\n\n"
        "Per the ENDF-6 manual, the available values are:\n\n"
        "    1 - General information\n"
        "    2 - Resonance parameter data\n"
        "    3 - Reaction cross sections\n"
        "    4 - Angular distributions for emitted particles\n"
        "    5 - Energy distributions for emitted particles\n"
        "    6 - Energy-angle distributions for emitted particles\n"
        "    7 - Thermal neutron scattering law data\n"
        "    8 - Radioactivity and fission-product yield data\n"
        "    9 - Multiplicities for radioactive nuclide production\n"
        "   10 - Cross sections for radioactive nuclide production\n"
        "   12 - Multiplicities for photon production\n"
        "   13 - Cross sections for photon production\n"
        "   14 - Angular distributions for photon production\n"
        "   15 - Energy distributions for photon production\n"
        "   16 - retired\n"
        "   17 - retired\n"
        "   18 - retired\n"
        "   19 - retired\n"
        "   20 - retired\n"
        "   21 - retired\n"
        "   22 - retired\n"
        "   23 - Photo- or electro-atomic interaction cross sections\n"
        "   24 - retired\n"
        "   25 - retired\n"
        "   26 - Electro-atomic angle and energy distribution\n"
        "   27 - Atomic form factors or scattering functions for photo-atomic\n"
        "        interactions\n"
        "   28 - Atomic relaxation data\n"
        "   30 - Data covariances obtained from parameter covariances and\n"
        "        sensitivities\n"
        "   31 - Data covariances for nu(bar)\n"
        "   32 - Data covariances for resonance parameters\n"
        "   33 - Data covariances for reaction cross sections\n"
        "   34 - Data covariances for angular distributions\n"
        "   35 - Data covariances for energy distributions\n"
        "   39 - Data covariances for radionuclide production yields\n"
        "   40 - Data covariances for radionuclide production cross\n"
        "        sections\n\n"
        "If the Iverf value is 0, this value is ignored.";
  }
  static Value_t defaultValue( const int ){ return std::nullopt; }
  static bool verify( const Value_t m, const int iverf ){
    if( iverf == 0 ) return true;
    return ( ( *m > 0 and *m < 11 ) or ( *m > 11 and *m < 16 ) or ( *m == 23 )
          or ( *m > 25 and *m < 29 ) or ( *m > 29 and *m < 36 ) or ( *m == 39 )
          or ( *m == 40 ) );
  }
};
