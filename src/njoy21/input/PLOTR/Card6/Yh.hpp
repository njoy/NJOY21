struct Yh {
  using Value_t = optional< double >;
  static std::string name(){ return "yh"; }
  static std::string description(){
    return
      "The yh argument specifies the upper bound for the y-axis.\n\n"
      "Checks that yh has a greater value than, or equal to, yl.\n\n"
      "If the y-scale is logarithmic, there is an imposed limit of 8 decades\n"
      "that the axis can span.  If a value greater than that is provided,\n"
      "VIEWR will cut off the lower y-values on the plot until 8 decades\n"
      "remain.";
  }
  static Value_t defaultValue( const Value_t yl ){
    if( yl != std::nullopt ){
      Log::info( "When using default values in PLOTR::Card6, the default\n"
                 "values should be used for all parameters.");
      std::exception e;
      throw e;
    }
    return std::nullopt;
  }
  static bool verify( const Value_t v, const Value_t yl ){
    return ( *v >= *yl );
  }
};
