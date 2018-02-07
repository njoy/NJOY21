struct Lib{
  using Value_t = int;

  static std::string name(){ return "lib"; }
  static std::string description(){
    return "The lib parameter specifies the library option.\n\n"
           " 1 = fast\n 2 = thermal\n 3 = cpm";
  }
  static bool verify( const Value_t lib ){
    return ( lib == 1 or lib == 2 or lib == 3 );
  }
};
