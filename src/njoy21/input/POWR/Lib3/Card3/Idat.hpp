struct Idat{
  using Value_t = int; // What is "i format"?
  static std::string name(){ return "idat"; }
  static std::string description(){
    return "The idat parameter specifies the date that the library is\n"
           "written.  For this module, the date is an integer. As such, it\n"
           "should be written as YYYYMMDD.";
  }
  static bool verify( const Value_t idat ){
    return idat > 19400000;
  }
};
