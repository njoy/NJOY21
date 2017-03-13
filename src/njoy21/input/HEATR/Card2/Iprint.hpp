struct Iprint {
  using Value_t = int;
  static std::string name(){ return "iprint"; }
  static std::string description(){
    return
      "";
  }

  static int defaultValue( Argument< Card1::Nplot >& ){ return 0; }
  
  static bool verify( Value_t v, Argument< Card1::Nplot >& nplot ){
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
