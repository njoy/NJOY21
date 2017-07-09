struct Thin2 {
  using Value_t = Quantity< ElectronVolt >;
  static std::string name() { return "thin2"; }

  static std::string description(){
    return 
        "The thin2 argument specifies the energy above which to use all\n"
        "energies (eV)---i.e., no thinning above this energy.\n";
  }
  static Value_t defaultValue( const Argument< Thin1 >& ){ 
    return 0.0*electronVolt; 
  }

  static bool verify( const Value_t& e2, const Argument<Thin1>& e1 ){ 
    if( e1.value < 0.0 ){
      return e2 > std::abs(e1.value)*electronVolt;
    }
    else{
      return (e2 >= 0.0*electronVolt);
    }
  }
};
