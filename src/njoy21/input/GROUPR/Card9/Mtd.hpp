struct Mtd {
  using Value_t = int;
  static std::string name(){ return "mfd"; }

  static std::string description(){
    return 
        "The mtd parameter specifies the ENDF Section to be processed. The \n"
        "mtd numbers are from the list of reactions on the input file. A \n"
        "negative value indiates all reactions from the previous entry to the\n"
        "absolute value of the the current entry.\n"
        "\n"
        "There are a few special options for mtd:\n"
        "     mtd          meaning\n"
        "     ---          -------\n"
        "     -n           process all mt numbers from the previous\n"
        "                          entry to n inclusive\n"
        "     221-250      reserved for thermal scattering\n"
        "     251          average elastic scatter cosine computed from \n"
        "                   File 4\n"
        "     252          continuos-slowing-down parameter computed from \n"
        "                   File 4\n"
        "     257          average energy\n"
        "     258          average lethargy\n"
        "     259          average inverse velocity (m/sec)\n";
  }

  static Value_t defaultValue( const Argument< Mfd >& ){ return 0; }
  static bool verify( const Value_t M, const Argument< Mfd >& mfd){
    if( mfd.value == 0 ){
      return true;
    }
    else{
      return M != 0;
    }
  }
};
