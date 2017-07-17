struct Iprint {
  using Value_t = int;
  static std::string name(){ return "iprint"; }
  static std::string description(){
    return
      "iprint is an optional integer input that controls the ouput printing.\n"
      "Valid inputs for iprint are 0 (minimal output), 1 (maximal output),\n"
      "and 2 (check). \n"
      "\n"
      "A typical way to use iprint is to set it zero for normal runs (which\n"
      "produce heating and damage values at all temperatures), and set it\n"
      "equal to 2 for the energy-balance check run.\n"
      "\n"
      "If HEATR's Card1 nplot input is set to a nonzero value, HEATR will\n"
      "produce a file of input for the VIEWR module containing detailed\n"
      "energy-balance test results. If this option is used, iprint must be \n"
      "set equal to 2.";
  }

  static Value_t defaultValue( Argument< HEATR::Card1::Nplot >& ){ return 0; }
  
  static bool verify( Value_t v, Argument< HEATR::Card1::Nplot >& nplot ){
    if ( nplot.value ){
      if (v != 2){
	Log::warning("Specifying a non-zero Card1 nplot argument"
		     " requires an iprint value of 2");
	Log::info( "nplot value: {}", nplot.value );
	Log::info( "iprint value: {}", v );
	return false;
      }
      return true;
    }
    return (v > -1) and (v < 3);
  }
};
