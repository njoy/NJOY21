struct Nsk {
  using Value_t = int;
  static std::string name(){ return "nsk"; }
  static std::string description(){
    return
      "The nsk argument is the intermolecular interference option, which\n"
      "takes an integer input of either 0, 1 or 2. A value of zero indicates\n"
      "that no intermolecular interference is desired, while values of 1 and\n"
      "2 correspond to vineyard and skold interference options, respectively.\n"
      "\n"
      "An nsk value of 1 or 2 will invoke the use of cards 17 and 18.\n"
      "Additionally, a value of 2 will invoke the use of card 19.\n"
      "\n"
      "nsk has a default value of 0.";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t& n ){ return n == 0 or n == 1 or n == 2; }
};
