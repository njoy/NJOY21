struct Ivers{
  using Value_t = int;
  static std::string name(){ return "ivers"; }
  static std::string description(){
    return "The ivers parameter specifies the file version number.  The\n"
           "default value is 0.";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t ivers ){
    return ivers >= 0;
  }
};
