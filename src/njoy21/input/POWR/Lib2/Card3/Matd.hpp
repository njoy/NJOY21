struct Matd{
  using Value_t = int;
  static std::string name(){ return "matd"; }
  static std::string description(){
    return "The matd parameter specifies the material to be processed.";
  }
  static bool verify( const Value_t matd ){
    return ( matd >= 0 and matd < 10000 );
  }
};
