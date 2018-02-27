struct Efmean {
  using Value_t = optional< Quantity< ElectronVolt > >;
  static std::string name(){ return "efmean"; }
  static std::string description(){
    return "The efmean parameter specifies the incident neutron energy in eV.\n"
           "Process the covariance matrix subsection whose energy interval\n"
           "includes efmean.  If ifissp = -1 and efmean is not specified,\n"
           "efmean defaults to 2.0e6.  But if there is only one subsection,\n"
           "process it and if the input efmean was not within this\n"
           "subsection's energy range, then redefine efmean to equal the\n"
           "average energy for this subsection.  This parameter is specified\n"
           "only if mfcov = 35.";
  }
  static Value_t defaultValue( const int ifissp, const int ){
    if( ifissp == -1 ) return 2.0E+06*electronVolt;
    return std::nullopt;
  }
  static bool verify( const Value_t efmean, const int, const int mfcov ){
    return ( mfcov != 35 or *efmean >= 0.0*electronVolt );
  }
};
