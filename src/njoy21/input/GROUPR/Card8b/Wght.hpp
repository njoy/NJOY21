struct Wght {
  using Value_t = ENDFtk::TAB1;
  static std::string name(){ return "wght"; }

  static std::string description() {
    return
        "The wght argument specifies an arbitrary weight function.\n"
        "\n"
        "The weight function is read in as a pseudo-ENDF TAB1 Record---only\n"
        "that it doesn't have the MAT MF MT numbers.";
  }

  static bool verify( const Value_t& W ){ 
    bool all_positive = std::all_of( W.yValues.begin(), W.yValues.end(),
                                     [](double v){ return v >= 0.0; } );
    return all_positive; }
};
