struct Matgg{
  using Value_t = int;
  static std::string name(){ return "matgg"; }
  static std::string description(){
    return "The matgg parameter specifies the material number for photoatomic\n"
           "data for each material.  As in ENDF-6, the default value is\n"
           "100*(matno/100). Valid values range from 100 to 9999, inclusively.";
  }
  static Value_t defaultValue( const Value_t matno ){ return 100*(matno/100); }
  static bool verify( const Value_t matgg, const Value_t ){
    return ( matgg > 0 and matgg < 10000 );
  }
};
