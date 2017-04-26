struct Nflmax {
  using Value_t = int;
  
  static std::string name(){ return "nflmax"; }
  static std::string description(){
    return
        "The nflmax parameter specifies the maximum number of computed flux\n"
        "points.";
  }

  static bool verify( Value_t s ){ return s > 0; }
};
