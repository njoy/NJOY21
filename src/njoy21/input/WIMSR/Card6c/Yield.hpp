struct Yield {
  using Value_t = double;

  static std::string name(){ return "yield"; }
  static std::string description(){
    return "The yield parameter specifies the fission yield of the fission\n"
           "product from the burnup of Card3::Mat.";
  }
  static bool verify( const Value_t yield ){
    return yield > 0.0 and yield <= 1.0;
  }
};
