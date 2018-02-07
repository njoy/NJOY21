struct Fis{
  using Value_t = std::vector< double >;
  static std::string name(){ return "fis"; }
  static std::string description(){
    return "The fis parameter specifies the fission values for this isotope.";
  }
};
