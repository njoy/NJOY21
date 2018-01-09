struct Idat{
  using Value_t = ???; // What is "i format"?
  static std::string name(){ return "idat"; }
  static std::string description(){
    return "The idat parameter specifies the date that the library is written.";
  }
  static bool verify( const Value_t idat ){
    return idat > 0;
  }
};
