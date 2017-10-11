struct Ylabl : public PLOTR::Card3::Title {
  using Value_t = PLOTR::Card3::Title::Value_t;
  static std::string name(){ return "ylabl"; }

  static std::string description(){
    return
      "The ylabl parameter is the label for the y-axis.\n"
      "The default value is 'cross section (barns)'.";
  }

  static Value_t defaultValue(){ return "cross section (barns)"; }
};
