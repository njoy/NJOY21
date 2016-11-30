struct Ncards {
  using Value_t = int;
  static std::string name(){ return "ncards"; }
  
  static std::string description(){
    return 
        "The ncards argument is an integer indicating the number of Card 5\n"
        "entries, each of which are descriptive ENDF TEXT records.\n"
        "\n"
        "(The absolute limit of ncards is 99999999999, but the practical \n"
        "limit is much, much smaller.)";
  }
  
  static Value_t defaultValue(){ return 0; }

  static bool verify( const Value_t& i ){ return i >= 0; }
};

