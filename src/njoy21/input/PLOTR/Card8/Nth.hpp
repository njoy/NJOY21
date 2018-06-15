struct Nth{
  using Value_t = int;
  static std::string name(){ return "nth"; }
  static std::string description(){
    return 
        "The nth variable's purpose changes depending on the mfd value.\n\n"
        "For mfd=3 or 5, nth is the number of the subsection to plot.\n"
        "   - This works for isomer production, delayed neutron, etc.\n\n"
        "For mfd=4, nth is the index for the Legendre coefficient (p1, p2, ...)"
        ".\n\n"
        "For mfd=6, this is the index for the incident energy.\n\n"
        "For gendf mfd=3 - Set nth to 0 for the flux per unit lethargy.\n"
        "                  Set nth to 1 for the cross section (default).\n\n"
        "For gendf mfd=6, nth is the energy group spectrum to be plotted:\n"
        "    nth=1 plots the 2-D spectrum for group 1\n"
        "    nth=2 plots the 2-D spectrum for group 2\n"
        "    etc.\n"
        "**There is no special meaning for 3-D gendf plots with mf=6.\n\n"
        "For mfd=7, nth is the index for the independent variables (alpha\n"
        "or beta).";
  }
  static Value_t defaultValue( const int, const int iverf, const int ){ 
    if( iverf == 0 ) return 0;
    return 1;
  }
  static bool verify( Value_t v, int mfd, int iverf, int jtype ){
    if( iverf == 0 ) return true;
    if( iverf == 1 ){ // GENDF
      if( mfd == 3 ){
        return ( ( v == 0 ) or 
                 ( v == 1 ) );
      }
      if( ( mfd == 6 ) and ( jtype == 0 ) ){
        return ( v > 0 ); // 2-D plots
      }
    } else{
      if( ( mfd == 3 ) or ( mfd == 5 ) ){
        return ( v > 0 );
      }
      if( mfd == 4 ){
        return ( ( v >= 0 ) and 
                 ( v < 65 ) );
      }
      if( mfd == 6 ){
        return ( ( v >= 0 ) and 
                 ( v < 2000 ) );
      }
      if( mfd == 7 ){
        return ( v >= 0 );
      }
    }
    return false;
  }
};
