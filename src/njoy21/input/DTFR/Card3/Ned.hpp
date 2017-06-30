struct Ned {
  using Value_t = int;
  static std::string name(){ return "ned"; }

  static std::string description(){
    return
      "Ned is the number of entries in the edit table. Note that this is\n"
      "not equal to the number of edit positions, it is the number of edit\n"
      "edit specification triplets to be read. Therefore, ned has to be\n"
      "greater than or equal to (iptotl - 3)."; 
 }

  static Value_t defaultValue( const Argument<Iptotl>& ){ return 0; }
  static bool verify( Value_t i, const Argument< Card3::Iptotl >& iptotl ){ 
    return iptotl.value - 3 <= i; 
  } 
};

