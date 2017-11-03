struct Temper : public argument::common::Tempd {
  using Value_t = optional< argument::common::Tempd::Value_t >;

  static std::string name(){ return "temper"; }
  static std::string description(){
    return
        "The temper argument specifies the absolute temperature (in Kelvin)\n"
        "for the material being plotted.";
  }
  static Value_t defaultValue( const int iverf ){
    if( iverf == 0 ) return std::nullopt;
    return 0.0*dimwits::kelvin;
  }
  static bool verify( const Value_t& t, const int iverf ){
    if( iverf == 0 ) return true;
    return argument::common::Tempd::verify(*t);
  }
};
