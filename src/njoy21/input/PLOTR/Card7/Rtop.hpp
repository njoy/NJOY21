struct Rtop {
  using Value_t =optional< double >;
  static std::string name(){ return "rtop"; }
  static std::string description(){
    return
      "The rtop argument specifies the upper bound for the alternate y-axis\n"
      "or the z-axis.\n\n"
      "Checks that rtop has a greater value than rbot.";
  }
  static Value_t defaultValue( const Value_t rbot ){
    if( rbot ){
      Log::error( "When using a default value in PLOTR::Card7, all values"
                  "should be defaulted." );
      throw std::exception();
    }
    return std::nullopt;
  }
  static bool verify( const Value_t v, 
                      const Value_t rbot ){
    return *v >= *rbot;
  }
};
