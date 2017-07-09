struct Iwt {
  using Value_t = int;
  static std::string name(){ return "iwt"; }

  static std::string description(){
    return 
        "The iwt option specfies the gamma group structure. The allowed\n"
        "values and their meanings are:\n"
        "     iwt          meaning\n"
        "     ---          -------\n"
        "      1           read in smooth weight function\n"
        "      2           constant\n"
        "      3           1/e\n"
        "      4           1/e + fission spectrum + thermal maxwellian\n"
        "      5           epri-cell lwr\n"
        "      6           (thermal) -- (1/e) -- (fission + fusion)\n"
        "      7           same with t-dep thermal part\n"
        "      8           thermal--1/e--fast reactor--fission + fusion\n"
        "      9           claw weight function\n"
        "     10           claw with t-dependent thermal part\n"
        "     11           vitamin-e weight function (ornl-5505)\n"
        "     12           vit-e with t-dep thermal part\n"
        "     -n           read flux calculations from input; use weight n\n"
        "      0           read in resonance flux from ninwt";
  }

  static bool verify( const Value_t i ) { 
    return abs(i) < 13;
  }
};
