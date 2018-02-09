struct Iwt {
  using Value_t = int;
  static std::string name(){ return "iwt"; }

  static std::string description(){
    return
  "   Set up calculation of weight functions or read in arbitary\n"
  "   function in the form of an ENDF TAB1 record or\n"
  "   read in parameters for an analytic weight function.\n\n"
  "      iwt     meaning\n"
  "      ---     -------\n"
  "       1      read in\n"
  "       2      constant\n"
  "       3      1/e + rolloffs\n";
  }

  static bool verify( const Value_t v ) {
    return (v == 1) or (v == 2) or (v == 3);
  }
};
