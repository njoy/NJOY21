struct Ngrid {
  using Value_t = int;
  static std::string name(){ return "ngrid"; }
  
  static std::string description(){
    return 
        "The ngrid argument is an integer indicating the number of energy\n"
        "grid points to be given as Card 6.";
  }
  
  static Value_t defaultValue(){ return 0; }

  static bool verify( const Value_t& i ){ return i >= 0; }
};

