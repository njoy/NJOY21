struct Nin {
  using Value_t = argument::common::Nin::Value_t;
  static std::string name(){ return "nin"; }
  static std::string description(){
    return
      argument::common::Nin::description() + "\n\n"
      "If the Iverf value is set to 0, this value is ignored.";
  }
  static Value_t defaultValue( const int ) { return 0; }
  static bool verify( const Value_t v, const int iverf ){
    if( iverf == 0 ) return true;
    return argument::common::Nin::verify( v );
  }
};
