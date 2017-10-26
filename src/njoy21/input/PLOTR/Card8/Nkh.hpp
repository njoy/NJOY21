struct Nkh{
  using Value_t = optional< int >;
  static std::string name(){ return "nkh"; }
  static std::string description(){
    return
        "The nkh variable's purpose changes depending on the mfd value.\n\n"
        "For mfd=3, 4, or 5, nkh is not used.\n\n"
        "For mfd=6, nkh is the number of the outgoing particle to plot.\n\n"
        "For gendf mfd=3 - Set nkh to 1 for p0 weighting (default).\n"
        "                  Set nkh to 2 for p1 weighting (total only).\n\n"
        "For 2-D gendf mfd=6, nkh is not used.\n\n"
        "**There is no special meaning for 3-D gendf plots with mf=6.\n\n"
        "For mfd=7, nkh = 1 selects normal s(alpha,beta)\n"
        "           nkh = 2 selects script s(alpha,-beta)\n"
        "           nkh = 3 selects script s(alpha,beta).";
  }
  static Value_t defaultValue( const int, const int ){
    return 1;
  }
  static bool verify( Value_t v, int mfd, int iverf ){
    std::cout << "Nkh iverf: " << iverf << " and v: " << *v << '\n';
    if( iverf == 0 or v == std::nullopt ) return true;
    if( iverf == 1 and mfd == 3 ) return ( *v == 1 or *v == 2 );
    if( iverf != 1 and mfd == 6 ) return ( *v > 0 );
    if( mfd == 7 ) return ( *v == 1 or *v == 2 or *v == 3 );
    return false;
  }
};
