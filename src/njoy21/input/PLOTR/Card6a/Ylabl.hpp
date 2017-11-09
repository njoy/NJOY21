struct Ylabl {
  using Value_t = std::string;
  static std::string name(){ return "ylabl"; }

  static std::string description(){
    return
      "The ylabl parameter is the label for the y-axis.\n"
      "The default value is 'cross section (barns)'.";
  }

  static Value_t defaultValue(){ return "cross section (barns)"; }
  static bool verify( const Value_t& s ){
    return ( s.length() < 61 );
  }
};
