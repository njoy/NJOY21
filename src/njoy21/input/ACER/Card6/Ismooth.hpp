struct Ismooth{
  using Value_t = int;
  static std::string name(){ return "ismooth"; }
  static std::string description(){
    return "The ismooth parameter specifies the smoothing option for the\n"
           "histogram of delayed neutron spectra at low energies using a\n"
           "sqrt(E) shape.  The default value is 1, implementing the\n"
           "smoothing.  The only other available option is 0, to turn off\n"
           "smoothing.";
  }
  static Value_t defaultValue(){ return 1; }
  static bool verify( const Value_t ismooth ){
    return ( ismooth == 0 or ismooth == 1 );
  }
};
