struct Tot{
  using Value_t = std::vector< double >;
  static std::string name(){ return "tot"; }
  static std::string description(){
    return "The tot parameter specifies the total cross section values to\n"
           "go with the lambda values.";
  }
};
