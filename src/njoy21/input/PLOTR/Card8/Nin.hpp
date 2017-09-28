struct Nin : public argument::common::Nin {
  using Value_t = argument::common::Nin::Value_t;
  static std::string description(){
    return
      argument::common::Nin::description() + "\n\n"
      "If the Iverf value is set to 0, this value is ignored.";
  }
  static bool verify( const Value_t v, const int iverf ){
    if( iverf == 0 ) return true;
    return argument::common::Nin::verify( v );
  }
};
