struct Mtd{
  using Value_t = optional< GROUPR::Card9::Mtd::Value_t >;
  static std::string name(){ return "mtd"; }
  static std::string description(){
    return 
        "The mtd parameter specifies the ENDF Section to be processed. The \n"
        "mtd numbers are from the list of reactions on the input file.\n"
        "\n"
        "There are a few special options for mtd:\n"
        "     mtd          meaning\n"
        "     ---          -------\n"
        "     221-250      reserved for thermal scattering\n"
        "     251          average elastic scatter cosine computed from \n"
        "                   File 4\n"
        "     252          continuous-slowing-down parameter computed from \n"
        "                   File 4\n"
        "     257          average energy\n"
        "     258          average lethargy\n"
        "     259          average inverse velocity (m/sec)\n"
        "If the Iverf value is 0, this value is ignored.\n";
  }

  static Value_t defaultValue( const int iverf ){
    if( iverf == 0 ) return std::nullopt;
    return 0;
  }
  static bool verify( const Value_t M, const int iverf ){
    if( iverf == 0 ) return true;
    return ( *M >= 0 and *M < 1000 );
  }
};
