struct Iwcol : public PLOTR::Card1::Ipcol {
  using Value_t = PLOTR::Card1::Ipcol::Value_t;
  static std::string name(){ return "iwcol"; }
  static std::string description(){
    return
      "The iwcol argument specifies the window color for this plot.\n\n"
      "There are 8 options for the window color:\n"
      "    0 - white\n"
      "    1 - navajo white\n"
      "    2 - blanched almond\n"
      "    3 - antique white\n"
      "    4 - very pale yellow\n"
      "    5 - very pale rose\n"
      "    6 - very pale green\n"
      "    7 - very pale blue\n"
      "    The default value is 0 specifying the window color as white.";
  }
};
