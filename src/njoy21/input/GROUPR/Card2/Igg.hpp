struct Igg {
  using Value_t = int;
  static std::string name(){ return "igg"; }

  static bool description(){
    return 
        "The igg option specfies the gamma group structure. The allowed\n"
        "values and their meanings are:\n"
        "     igg          meaning\n"
        "     ---          -------\n"
        "      0           none\n"
        "      1           arbitrary structure (read in)\n"
        "      2           csewg 94-group structure\n"
        "      3           lanl 12-group structure\n"
        "      4           steiner 21-group gamma-ray structure\n"
        "      5           straker 22-group structure\n"
        "      6           lanl 48-group structure\n"
        "      7           lanl 24-group structure\n"
        "      8           vitamin-c 36-group structure\n"
        "      9           vitamin-e 38-group structure\n"
        "     10           vitamin-j 42-group structure";
  }

  static bool verify( const Value_t i ) { return ( i > -1 ) and ( i < 11 ); }
};
