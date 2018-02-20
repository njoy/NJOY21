struct Matn {
  using Value_t = int;
  static std::string name(){ return "matn"; }
  static std::string description(){
    return "The matn parameter specifies the material number.  Allowable\n"
           "values range from 1 to 9999.";
  }
  static bool verify( const Value_t matn ){
    return ( matn > 0 and matn < 10000 );
  }
};
