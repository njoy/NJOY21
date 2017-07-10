struct Thin3 {
  using Value_t = int;
  static std::string name() { return "thin3"; }

  static std::string description(){
    return 
        "The thin3 (or iskf) argument, specifies the skip factor. Use every\n"
        "iskf-th energy between e1 and e2 (thin1 and thin2 respectively), or\n"
        "rsigz reference sigma zero.\n"
        "\n"
        "The thin3 value must be greater than 0 and is only used when the \n"
        "thin1 value is negative.";
  }
  static Value_t defaultValue( const Argument< Thin1 >& ){ return 0; }
  static bool verify( const Value_t& iskf, const Argument<Thin1>& e1 ){ 
    if( e1.value >= 0.0 ){
      return iskf > 1; 
    }
    else{
      return true; // if e1.value > 0, this value does not matter
    }
  }
};
