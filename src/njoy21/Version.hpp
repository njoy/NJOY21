class Version{
public:
  static const int majorVersion{1}; // Do not change 
  static const int minorVersion{0};
  static const int patchVersion{0};

  static const std::string version;
};

const std::string Version::version{ 
  std::to_string( Version::majorVersion ) + "." + 
  std::to_string( Version::minorVersion ) + "." +
  std::to_string( Version::patchVersion ) };
