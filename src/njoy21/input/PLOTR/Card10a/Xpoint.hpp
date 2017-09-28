struct Xpoint {
  using Value_t = float;
  static std::string name(){ return "xpoint"; }
  static std::string description(){
    return
      "The xpoint argument specifies the x position of the tip of the vector\n"
      "pointing from the tag title to the curve.\n\n"
      "A value of less than or equal to zero is used to omit the vector.";
  }
  static bool verify( Value_t ){
    return true;
  }
};
