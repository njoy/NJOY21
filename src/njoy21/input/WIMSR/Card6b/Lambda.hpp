struct Lambda {
  using Value_t = double;

  static std::string name(){ return "lambda"; }
  static std::string description(){
    return "The lambda parameter specifies the decay constant of the parent\n"
           "nuclide of the decay product (s-1).";
  }
  static bool verify( const Value_t lambda ){
    return lambda > 0.0;
  }
};
