struct Ngg {
  using Value_t = int;
  static std::string name(){ return "ngg"; }

  static std::string description(){
    return
        "The ngg parameter specifies the number of gamma groups enabling the \n"
        "user to create a unique group structure.\n"
        "\n"
        "The group boundaries are given in Card 4 Egg.";
  }
  static bool verify( Value_t n ){ return n > 0; }
};
