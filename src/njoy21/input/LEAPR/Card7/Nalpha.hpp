struct Nalpha {
  using Value_t = int;
  static std::string name(){ return "nalpha"; }
  static std::string description(){
    return
      "The nalpha argument is the number of alpha values for S(a,b).\n"
      "\n"
      "nalpha must be a positive integer.";
  }
  static bool verify( const Value_t& nalpha ){ return nalpha > 0; }
};
