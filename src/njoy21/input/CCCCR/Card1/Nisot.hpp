struct Nisot{
  using Value_t = int;
  static std::string name(){ return "nisot"; }
  static std::string description(){
    return "The nisot parameter specifies the output unit for isotxs.  If\n"
           "set to 0, no isotxs input will be read.";
  }
  static Value_t defaultValue( const Value_t ){ return 0; }
  static bool verify( const Value_t nisot, const Value_t nin ){
    return ( nisot == 0 or ( nisot > -100 and nisot < -19
             and std::abs( nisot ) != nin ) );
  }
};
