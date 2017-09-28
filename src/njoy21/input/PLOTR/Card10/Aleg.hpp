struct Aleg : public PLOTR::Card3::Title {
  using Value_t = PLOTR::Card3::Title::Value_t;
  static std::string name(){ return "aleg"; }
  static std::string description(){
    return
      "The aleg parameter is the title for the curve tak or legend block.\n"
      "60 characters max.  The default is a blank string.";
  }
};
