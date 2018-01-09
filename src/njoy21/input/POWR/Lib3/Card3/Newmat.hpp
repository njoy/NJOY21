struct Newmat{
  using Value_t = int;
  static std::string name(){ return "newmat"; }
  static std::string description(){
    return "The newmat parameter specifies the number of materials to be\n"
           "added.";
  }
  static bool verify( const Value_t newmat ){
    return newmat >= 0;
  }
};
