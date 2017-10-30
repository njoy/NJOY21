struct Xlabl {
  using Value_t = PLOTR::Card3::Title::Value_t; // std::string
  static std::string name(){ return "xlabl"; }

  static std::string description(){
    return
      "The xlabl parameter is the label for the x-axis.\n"
      "The default value is 'energy(ev)'.";
  }

  static Value_t defaultValue(){ return "energy (ev)"; }
  static bool verify( const Value_t& s ){ 
    return PLOTR::Card3::Title::verify(s);
  }
};
