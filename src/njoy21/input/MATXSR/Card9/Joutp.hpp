struct Joutp{
  using Value_t = int;
  static std::string name(){ return "joutp"; }
  static std::string description(){
    return "The joutp parameter specifies the output particle id for each\n"
           "data type.";
  }
  static bool verify( const Value_t joutp ){ return joutp >= 0; }
};
