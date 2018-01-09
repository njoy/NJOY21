struct Mode{
  using Value_t = int;
  static std::string name(){ return "mode"; }
  static std::string description(){
    return "The mode parameter specifies what should be done with the\n"
           "isotopes in respect to the cpm library.\n"
           " 0 = create a new library (default)\n"
           " 1 = add the isotope to the existing library\n"
           " 2 = replace the isotope already on the library";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t mode ){
    return ( mode == 0 or mode == 1 or mode == 2 );
  }
};
