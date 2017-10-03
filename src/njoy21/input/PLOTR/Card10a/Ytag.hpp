struct Ytag {
  using Value_t = double;
  static std::string name(){ return "ytag"; }
  static std::string description(){
    return
      "The ytag argument specifies the y position of the tag title.\n";
  }
  static bool verify( Value_t ){
    return true;
  }
};
