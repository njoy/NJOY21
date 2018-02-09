struct Iopt{
  using Value_t = int;
  static std::string name(){ return "iopt"; }
  static std::string description(){
    return "The iopt parameter specifies the add option.\n"
           " 0 = materials will be read in"
           " 1 = use all materials found on ngendf";
  }
  static bool verify( const Value_t iopt ){
    return ( iopt == 1 or iopt == 0 );
  }
};
