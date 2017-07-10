struct Wght {
  using Value_t = ENDFtk::TAB1;
  static std::string name(){ return "wght"; }

  static std::string description() {
    return
      "The wght argument specifies an arbitrary weight function. Weight "
      "\n"
      "The weight function is read in as a pseudo-ENDF TAB1 Record---only\n"
      "that it doesn't have the MAT MF MT numbers. Weight values are required\n"
      "to be non-negative.";
  }

  static bool verify( const Value_t& W ){ 
    const bool all_positive = std::all_of( W.y().begin(), W.y().end(),
                                           [](double v){ return v >= 0.0; } );
    return all_positive;
  }
};
