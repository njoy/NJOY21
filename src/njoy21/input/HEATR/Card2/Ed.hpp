struct Ed {
  using Value_t = Quantity<ElectronVolts>;
  static std::string name(){ return "ed"; }
  static std::string description(){
    return
      "ed is an optional integer argument that represents the damage\n"
      "displacement energy, which is the energy (eV) required to displace an\n"
      "atom from its lattice position.\n"
      "\n"
      "The default value for ed is defined by its corresponding element.\n"
      "---Element----ed (eV)------Element----ed (eV )---\n"
      "|     Be         31     |     Co         40     | \n"
      "|     C          31     |     Ni         40     | \n"
      "|     Mg         25     |     Cu         40     | \n"
      "|     Al         27     |     Zr         40     | \n"
      "|     Si         25     |     Nb         40     | \n"
      "|     Ca         40     |     Mo         60     | \n"
      "|     Ti         40     |     Ag         60     | \n"
      "|     V          40     |     Ta         90     | \n"
      "|     Cr         40     |     W          90     | \n"
      "|     Mn         40     |     Au         30     | \n"
      "|     Fe         40     |     Pb         25     | \n"
      "------------------------------------------------- \n"
      "\n"
      "If the default value is used, and the card2 matd number does not \n"
      "correspond to any of the above materials, then a default value of \n"
      "25 eV is used."; 
  }

  static Value_t defaultValue( Argument< HEATR::Card2::Matd >& matd ){ 
    int mat = matd.value;
    int za = 1000 * std::floor( mat / 100 );
    int iz = std::round( za / 1000 );
    auto default_val = 25.0 * electronVolts;

    if      ( iz == 4  ){ default_val = 31.0 * electronVolts; }
    else if ( iz == 6  ){ default_val = 31.0 * electronVolts; }
    else if ( iz == 12 ){ default_val = 25.0 * electronVolts; }
    else if ( iz == 13 ){ default_val = 27.0 * electronVolts; }
    else if ( iz == 14 ){ default_val = 25.0 * electronVolts; }
    else if ( iz == 20 ){ default_val = 40.0 * electronVolts; }
    else if ( iz >= 22 and iz <= 29 ){ default_val = 40.0 * electronVolts; }
    else if ( iz == 40 ){ default_val = 40.0 * electronVolts; }
    else if ( iz == 41 ){ default_val = 40.0 * electronVolts; }
    else if ( iz == 42 ){ default_val = 60.0 * electronVolts; }
    else if ( iz == 47 ){ default_val = 60.0 * electronVolts; }
    else if ( iz == 73 ){ default_val = 90.0 * electronVolts; }
    else if ( iz == 74 ){ default_val = 90.0 * electronVolts; }
    else if ( iz == 79 ){ default_val = 30.0 * electronVolts; }
    else if ( iz == 82 ){ default_val = 25.0 * electronVolts; }
    else { 
      default_val = 25.0 * electronVolts; 
      Log::info( "Mat Number: {}", mat );
      Log::warning( "Material specific default value not found in table\n"
                    "default value of 25 eV used.\n" );
    }
    return default_val;

  }

  static bool verify( const Value_t& i,
                      const Argument< HEATR::Card2::Matd >& ){ 
    return (i >= 0.0*electronVolts); 
  }
};
