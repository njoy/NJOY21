struct P1flx {
  using Value_t = std::vector<double>

  static std::string name(){ return "p1flx"; }
  static std::string description(){
    return "The p1flx parameter is the current spectrum.  (Card4:Jp1) entries\n"
           "are read and the rest are set with the default p1-flux calculated\n"
           "by njoy.";
  }
  static bool verify( const Value_t p1flx, const unsigned int ngnd,
                      const unsigned int jp1 ){
    return p1flx.size() == jp1 and p1flx.size() <= ngnd;
  }
};
