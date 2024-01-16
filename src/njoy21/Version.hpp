class Version{
public:
  static constexpr int majorVersion{1}; // Do not change
  // Change whenever new capability is implemented
  static constexpr int minorVersion{2};
  // Change whenever merge to master branch is done
  static constexpr int patchVersion{74};

  static std::string version(){
    return std::to_string( majorVersion ) + "." +
           std::to_string( minorVersion ) + "." +
           std::to_string( patchVersion );
  }
};
