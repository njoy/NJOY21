struct Nmix {
  using Value_t = int;
  static std::string name(){ return "nmix"; }

  static std::string description() {
    return 
        "The nmix argument specifies the number of atom types in a mixed\n"
        "moderator. \n"
        "\n"
        "Some materials (like benzine) describe the scattering from the \n"
        "molecule. For these materials, nmix should be 2. Other materials\n"
        "describe scattering off of a single atom in the molecule, like\n"
        "hydrogen in water. Most materials fall in this category; nmix should\n"
        "be 1 for these.";
  }

  static Value_t defaultValue(){ return 1; }
  static bool verify( const Value_t& nmix ){
    return ( nmix == 1 ) or ( nmix == 2);
  }
};
