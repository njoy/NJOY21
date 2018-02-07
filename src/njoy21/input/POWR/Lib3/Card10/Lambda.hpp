struct Lambda{
  using Value_t = std::vector< double >;
  static std::string name(){ return "lambda"; }
  static std::string description(){
    return "The lambda parameter specifies the resonance goldstein lambdas\n"
           "for this nuclide.";
  }
};
