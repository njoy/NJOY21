struct Jinp{
  using Value_t = int;
  static std::string name(){ return "jinp"; }
  static std::string description(){
    return "The jinp parameter specifies the input particle id for each\n"
           "data type.";
  }
  static bool verify( const Value_t jinp ){ return jinp >= 0; }
};
