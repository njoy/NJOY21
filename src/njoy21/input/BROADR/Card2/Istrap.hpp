struct Istrap {
  using Value_t = int;
  static std::string name(){ return "istrap"; }
  static std::string description(){
    return
      "The istrap argument is an optional integer argument that acts as a\n"
      "boolean flag. As such, only values of zero or one are permitted. When\n"
      "unspecified this argument defaults to zero.\n"
      "\n"
      "When the istrap value is one, bootstrapping is permitted. In the default\n"
      "behavior, each final temperature is computed by broadening directly\n"
      "from temp1. When bootstrapping is permitted, a given final temperature\n"
      "is computed from the previously computed final temperature.\n"
      "Bootstrapping is faster due to the thinning in the previous step\n"
      "However, error accumulates between broadening steps.";
  }

  static int defaultValue(){ return 0; }
  static bool verify( Value_t v ){ return (v == 0) or (v == 1); }
};
