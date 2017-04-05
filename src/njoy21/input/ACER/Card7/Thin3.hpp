struct Thin3 {
  using Value_t = int;
  static std::string name() { return "thin3"; }

  static std::string description(){
    return 
        "The thin3 (or iskf) argument, specifies the skip factor. Use every\n"
        "iskf-th energy between e1 and e2 (thin1 and thin2 respectively), or\n"
        "rsigz reference sigma zero.";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t& iskf ){ return iskf >= 0; }
};
