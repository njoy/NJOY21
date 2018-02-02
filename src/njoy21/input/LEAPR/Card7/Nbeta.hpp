struct Nbeta {
  using Value_t = int;
  static std::string name(){ return "nbeta"; }
  static std::string description(){
    return
      "The nbeta argument is the number of beta values provided for S(a,b).\n"
      "\n"
      "nbeta must be a positive integer.";
  }
  static bool verify( const Value_t& nbeta ){ return nbeta > 0; }
};
