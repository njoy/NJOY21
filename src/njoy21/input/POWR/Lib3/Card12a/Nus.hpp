struct Nus{
  using Value_t = std::vector< double >;
  static std::string name(){ return "nus"; }
  static std::string description(){
    return "The nus parameter specifies the nu values for this isotope.";
  }
};
