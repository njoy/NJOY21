struct Thin1 {
  using Value_t = double;
  static std::string name() { return "thin1"; }

  static std::string description(){
    return 
        "The type of thinning is determined by the sign of thin1:\n"
        "  - positive or zero: energy skip. This option is obsolete and not\n"
        "     recommended\n"
        "  - negative: integral fraction.\n"
        "\n"
        "The thin1 argument specifies the energy below which to use all\n"
        "energies (eV)---i.e., no thinning below this energy--- or the \n"
        "iwtt weighting option (1=flat,2=1/E).\n"
        "\n"
        "When thin1=2, the 1/E weighting has a weighting of 10 when E < 0.1.";
  }
  static Value_t defaultValue(){ return 0.0; }
};
