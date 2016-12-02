struct Ncards {
  using Value_t = int;
  static std::string name(){ return "ncards"; }
  
  static std::string description(){
    return 
        "The ncards argument is an integer indicating the number of Card 5\n"
        "entries, each of which are descriptive ENDF TEXT records.";
  }
  
  static Value_t defaultValue(){ return 0; }

  static bool verify( const Value_t& i ){ return i >= 0; }
};

