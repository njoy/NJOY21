struct Ngn {
  using Value_t = int;
  static std::string name(){ return "ngn"; }

  static std::string description(){
    return
        "The ngn parameter specifies the number of groups enabling the user\n"
        "to create a unique group structure.\n"
        "\n"
        "The group boundaries are given in Card 6b.";
  }
  static bool verify( Value_t n ){ return n > 0; }
};
