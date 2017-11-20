struct Mfd {
  using Value_t = int;
  static std::string name(){ return "mfd"; }

  static std::string description(){
    return 
        "The mfd parameter specfies the ENDF File to be processed. The\n"
        "allowed mfd values and their meanings are:\n"
        "     mfd          meaning\n"
        "     ---          -------\n"
        "      3           cross section or yield vector\n"
        "      5           fission chi by short-cut method\n"
        "      6           neutron-neutron matrix (mf4/5)\n"
        "      8           neutron-neutron matrix (mf6)\n"
        "     12           photon prod. xsec (photon yields given, mf12)\n"
        "     13           photon prod. xsec (photon xsecs given, mf13)\n"
        "     16           neutron-gamma matrix (photon yields given)\n"
        "     17           neutron-gamma matrix (photon xsecs given)\n"
        "     18           neutron-gamma matrix (mf6)\n"
        "     21           proton production matrix (mf6)\n"
        "     22           deuteron production (mf6)\n"
        "     23           triton production (mf6)\n"
        "     24           he-3 production (mf6)\n"
        "     25           alpha production (mf6)\n"
        "     26           residual nucleus (a>4) production (mf6)\n"
        "     31           proton production matrix (mf4)\n"
        "     32           deuteron production (mf4)\n"
        "     33           triton production (mf4)\n"
        "     34           he-3 production (mf4)\n"
        "     35           alpha production (mf4)\n"
        "     36           residual nucleus (a>4) production (mf4)\n"
        "    1zzzaaam       nuclide production for zzzaaam\n"
        "                     subsection from file 3\n"
        "    2zzzaaam       nuclide production for zzzaaam\n"
        "                     subsection from file 6\n"
        "    3zzzaaam       nuclide production for zzzaaam\n"
        "                     subsection from file 9\n"
        "    4zzzaaam       nuclide production for zzzaaam\n"
        "                     subsection from file 10\n"
        "\n"
        "For more information, see the NJOY manual.";
  }

  static bool verify( const Value_t m ){
    if( (m < -1) or (m == 1) or (m == 2) or (m == 4) or
        (m == 7) or (m == 9 ) or  (m == 11) or 
        (m == 14) or (m == 15) or
        ( (m > 18) and (m < 21 ) ) or
        ( (m > 26) and (m < 31 ) ) or
        ( (m > 36) and (m < 1E7) )
        ){
      return false;
    }
    else{
      return true;
    }
  }
};
