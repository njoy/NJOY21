struct Efmean {
  using Value_t = optional< Quantity< electronVolt > >;
  static std::string name(){ return "efmean"; }
  static std::string description(){
    return "The efmean parameter specifies the incident neutron energy in eV.\n"
           "Process the covariance matrix subsection whoe energy interval\n"
           "includes efmean.  If ifissp = -1 and efmean is not specified,
           "efmean defaults to 2.0e6.  But if there is only one subsection,\n"
           "process it and if the input efmean was not within this\n"
           "subsection's energy range, then redefine efmean to equal the\n"
           "average energy for this subsection.  This parameter is specified\n"
           "only if mfcov = 35.";
  }
  static Value_t defaultValue( const int ifissp ){
    if( ifissp == -1 ) return 2.0E+-6*eV;
    return std::nullopt;
  }
  static bool verify( const Value_t efmean, const int ){
    return ( *efmean >= 0.0*eV );
  }
};
