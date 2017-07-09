struct Temp2 {
  using Value_t = std::vector< Quantity< Kelvin > >;
  static std::string name(){ return "temp2"; }
  static std::string description(){
    return
      "temp2 is a series of arguments specifying temperatures in Kelvin.\n"
      "The argument values specify the final temperatures to which the\n"
      "reference temperature (see card 2 temp1 argument) cross sections\n"
      "should be broadened.\n"
      "\n"
      "Each temp2 entry is required to be greater than or equal to the\n"
      "corresponding card 2 temp1 argument. In the case that a temp2 value\n"
      "is equal to the temp1 value, the cross sections are thinned only.\n"
      "\n"
      "When boostrapping is requested (see card 2 istrap argument), the\n"
      "temp2 arguments are required to be sorted from least to greatest.";
  }

  static bool verify( Value_t v,
		      const Argument< Card2::Ntemp2 >& ntemp2,
		      const Argument< Card2::Istrap >& istrap,
		      const Argument< Card2::Temp1 >& temp1 ){
    
    if ( long( v.size() ) != ntemp2.value ){
      if ( long( v.size() ) < ntemp2.value ){
        Log::warning( "Encountered fewer temp2 arguments than"
		      " specified in card2 ntemp2 argument" );
      } else {
        Log::warning( "Encountered more temp2 arguments than"
		      " specified in card2 ntemp2 argument" );
      }
      Log::info( "ntemp2: {}", ntemp2.value );
      Log::info( "temp2 entries: {}", v.size() );
      return false;
    }
    
    auto position =
      std::find_if( std::begin(v), std::end(v),
		    [&temp1]( auto& entry ){ return entry < temp1.value; } );
    if ( position != std::end(v) ){
      Log::warning("Encountered temp2 argument less than temp1 argument" );
      Log::info("temp1 argument: {}", temp1.value );
      Log::info("temp2 argument [{}]: {}",
        std::distance( std::begin(v), position ), *position );
      return false;
    }

    if ( istrap.value ){
      position = std::is_sorted_until( std::begin(v), std::end(v) );
      if ( position != std::end(v) ){
        Log::warning("Encountered unsorted temp2 arguments in bootstrap mode" );
        const auto distance = std::distance( std::begin(v), position );
        Log::info("temp2 argument [{}]: {}", distance - 1, position[-1] );
        Log::info("temp2 argument [{}]: {}", distance, *position );
        return false;
      }
    }
    return true;
  }
};
