struct Iptotl {
  using Value_t = int;
  static std::string name(){ return "iptotl"; }

  static std::string description(){
    return
      "iptotl is the position of the total cross section. It is used to\n"
      "both determine the total cross section's position in the table, as\n"
      "well as the number of special edit positinos at the front of the \n"
      "table (iptotl - 3).\n"
      "\n"
      "For this reason, iptotl >= 3."; 
  }

  static bool verify( Value_t i ){ return 3 <= i; } 
};

