struct Yl {
  using Value_t = float;
  static std::string name(){ return "yl"; }
  static std::string description(){
    return
      "The yl argument specifies the lower bound for the y-axis.\n"
      "If the y-axis is a linear plot (card4::itype), the default value is\n"
      "0.0.\n\n"
      "If the y-axis is a logarithmic plot (card4::itype), the default\n"
      "value is set to 1.0E-07.\n\n"
      "VIEWR imposes a limit for logarithmic plots to no more than 8 decades\n"
      "on the y-axis.  If more than 8 decades are present, the lower values\n"
      "will be cut off until only 8 decades remain.\n\n"
      "If using the default value, the default value should be used for yh\n"
      "and ystep as well.";
  }
  static Value_t defaultValue( const int itype ){
    if( std::abs( itype ) == 1 or std::abs( itype )  == 3 ){
      return 0.0;
    }
    return 1.0e-07;
  }
  static bool verify( Value_t v, const int itype ){
    if( std::abs( itype ) == 2 or std::abs( itype ) == 4 ){
      return ( v > 0.0 );
    }
    return true;
  }
};
