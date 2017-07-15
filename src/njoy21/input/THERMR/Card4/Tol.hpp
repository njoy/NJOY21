struct Tol {
  using Value_t = double;
  static std::string name(){ return "tol"; }
  static std::string description(){
    return
      "The tol argument is the tolerance for interpolating between Bragg\n"
      "edges. The energy grid for coherent elastic scattering is produced\n"
      "adaptively such that the energy grid from just below one Bragg edge\n"
      "to just below the next higher one is subdivided by halving until the\n"
      "linear interpolation is within a specified fractional tolerance (tol)\n"
      "of the exact cross section at every point.\n"
      "\n"
      "tol must be some decimal value greater than 1.0e-6.";
  }
  
  static bool verify( const Value_t tol ){
    return ( 1.0e-6 < tol ); 
  }
};
