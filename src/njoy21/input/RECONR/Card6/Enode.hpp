struct Enode {
  using Value_t = std::vector< Quantity< ElectronVolt > >;
  static std::string name(){ return "enode"; }

  static std::string description() {
    return 
        "The enode argument is ";
  }

  static bool verify( const Value_t& node, 
                      const Argument< Card3::Ngrid >& ngrid){

    auto found = std::find_if(node.begin(), node.end(), 
                              [](auto& E){ return E > 0.0*electronVolt; });
    if (found != node.end()){
      Log::warning("Negative energy grid point ({}) found at index {}",
                   *found, std::distance(node.begin(), found));
      return false;

    } else {
      return (long(node.size()) == ngrid.value);
    }

  }
};
