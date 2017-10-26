struct Ntp{
  using Value_t = optional< int >;
  static std::string name(){ return "ntp"; }
  static std::string description(){
    return
        "The ntp variable's purpose changes depending on the mfd value.\n\n"
        "For mfd=3, 4, or 5, ntp is not used.\n\n"
        "For mfd=6, ntp is the number of dependent variables in the cycle\n"
        "to plot (or angle number for law 7).\n\n"
        "For gendf mfd=3 - Set ntp to 1 for infinite dilution (default).\n"
        "                  Set ntp to 2 for the next lowest sigma-zero values\n"
        "                  etc.\n\n"
        "For gendf mfd=6, ntp is not used.\n\n"
        "**There is no special meaning for 3-D gendf plots with mf=6.\n\n"
        "For mfd=7, ntp = 1 to use alpha as the independent variable (default)."
        "\n           ntp = 2 to use beta as the independent variable.";
  }
  static Value_t defaultValue( const int, const int ){
    return 1;
  }
  static bool verify( const Value_t v, const int mfd, const int iverf ){
    std::cout << "Ntp iverf: " << iverf << " and v: " << *v << '\n';
    if( iverf == 0 or v == std::nullopt ) return true;
    if( iverf == 1 and mfd == 3 ) return ( *v == 1 or *v == 2 );
    if( iverf != 1 and mfd == 6 ) return ( *v > 0 );
    if( mfd == 7 ) return ( *v == 1 or *v == 2 );
    return false;
  }
};
