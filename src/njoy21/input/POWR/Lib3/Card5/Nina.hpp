struct Nina{
  using Value_t = int;
  static std::string name(){ return "nina"; }
  static std::string description(){
    return "The nina parameter specifies the nina indicator, specifying\n"
           "whether file2 and file4 data are available and should be read\n"
           "for absorption.\n"
           " 0 = normal\n"
           " 1 = no file2 data, calculate absorption in file4\n"
           " 2 = no file 2 data, read in absorption in file4\n"
           " 3 = read in all file2 and file4 data";
  }
  static bool verify( const Value_t nina ){
    return ( nina == 0 or nina == 1 or nina == 2 or nina == 3 );
  }
};
