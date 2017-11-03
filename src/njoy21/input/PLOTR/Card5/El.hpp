struct El {
  using Value_t = optional< double >;
  static std::string name(){ return "el"; }
  static std::string description(){
    return
      "The el argument specifies the lower bound for the energy (x) axis.\n\n"
      "If the x-axis is a linear plot (card4::itype), the default value is\n"
      "0.0.  If the card4::xtag value was left as the default, it will be\n"
      "set here as 0.0.\n\n"
      "If the x-axis is a logarithmic plot (card4::itype), the default\n"
      "value is set to 1.0E-07.  Again, if the card4::xtag value was left\n"
      "as the default, it will be set here as 1.0E-07.\n\n"
      "VIEWR imposes a limit for logarithmic plots to no more than 13 decades\n"
      "on the x-axis.  If more than 13 decades are present, the lower values\n"
      "will be cut off until only 13 decades remain.\n\n"
      "If using the default value, the default value should be used for eh\n"
      "and xstep as well.";
  }
  static Value_t defaultValue( const int ){ return std::nullopt; }
  static bool verify( Value_t v, const int itype ){
    if( v == std::nullopt ) return true;
    if( std::abs( itype ) == 1 or std::abs( itype ) == 2 ){
      return ( *v >= 0.0 );
    }
    return ( *v > 0.0 );
  }
};
