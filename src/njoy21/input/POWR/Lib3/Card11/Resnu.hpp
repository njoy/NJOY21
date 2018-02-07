struct Resnu{
  using Value_t = std::vector< double >;
  static std::string name(){ return "resnu"; }
  static std::string description(){
    return "The resnu parameter specifies the nrg nus values to go with\n"
           "the lambda values.";
  }
};
