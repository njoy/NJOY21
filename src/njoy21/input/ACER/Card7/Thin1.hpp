struct Thin1 {
  using Value_t = double;
  static std::string name() { return "thin1"; }

  static std::string description(){
    return 
        "The thin1 argument specifies the energy below which to use all\n"
        "energies (eV) or the iwtt weighting option (1=flat,2=1/E).\n"
        "\n"
        "When thin1=2, the 1/E weighting has a weighting of 10 when E < 0.1.";
  }
  static bool verify( const Value_t& e1 ){
    return ( e1 > 0.0 );
  }
};
