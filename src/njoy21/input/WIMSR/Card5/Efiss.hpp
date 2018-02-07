struct Efiss {
  using Value_t = double;
  static std::string name(){ return "efiss"; }
  static std::string description(){
    return "The efiss parameter specifies the energy released per fission.";
  }
  static bool verify( const Value_t efiss ){
    return efiss > 0;
  }
};
