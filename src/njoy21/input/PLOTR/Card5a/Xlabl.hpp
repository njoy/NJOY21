struct Xlabl : public PLOTR::Card3::Title {
  using Value_t = PLOTR::Card3::Title::Value_t;
  static std::string name(){ return "xlabl"; }

  static std::string description(){
    return
      "The xlabl parameter is the label for the x-axis.\n"
      "The default value is 'energy(ev)'.";
  }

  static Value_t defaultValue(){ return "energy (ev)"; }
};
