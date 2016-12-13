struct Iopt {
  using Value_t = int;

  static std::string name(){ return "iopt"; }
  static bool description(){
    return
        "The parameter iopt specifies the kind of ACE data being produced:\n"
        "  1: fast data\n"
        "  2: thermal data\n"
        "  3: dosimetry data\n"
        "  4: photo-atomic data\n"
        "  5: photo-nuclear data\n"
        "  7: read type 1 ace files to print or edit\n"
        "  8: read type 2 ace files to print or edit\n";
  }

  static bool verify( const Value_t v ){
    return ( std::abs( v ) == 1 ) or // fast data
           ( std::abs( v ) == 2 ) or // thermal data
           ( std::abs( v ) == 3 ) or // dosimetry data
           ( std::abs( v ) == 4 ) or // photo-atomic data
           ( std::abs( v ) == 5 ) or // photo-nuclear data
           ( std::abs( v ) == 7 ) or // read type 1 ace files to print or edit
           ( std::abs( v ) == 8 );   // read type 2 ace files to print or edit
  }
};
