struct Iprint {
  using Value_t = int;
  static std::string name(){ return "iprint"; }

  static std::string description(){
    return
        "The value of iprint is used to control the output format. If it\n"
	"is equal to 0, a conventional DTF-type table is produced. Normally\n"
	"the print flag iprint is set to 1.\n"
	"\n"
	"iprint must be equal to either 0 or 1.";
  }

  static bool verify( Value_t i ){ return i == 0 || i == 1; }
};

