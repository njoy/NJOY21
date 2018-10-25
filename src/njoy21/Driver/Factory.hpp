class Factory {
  using Directory = std::unordered_set< std::string >;
  CommandLine commandLine;
  std::unique_ptr< io::Manager > manager;
  Directory legacy;
  Directory modern;
  
  #include "njoy21/Driver/Factory/src/setupManager.hpp"
  #include "njoy21/Driver/Factory/src/setupLegacyDirectory.hpp"

  static Directory setupModernDirectory( CommandLine& commandLine ){
    return ( commandLine.legacySwitch ) ? Directory() : Directory();
  }

  template< typename First, typename Second, typename... Args >
  static void cycle( First&& first, Second&& second, Args&... args ){
    while ( first( args... ) and second( args... ) ){}    
  }
  
public:
  Factory( int argc, char* argv[] ) :
    commandLine( argc, argv ),
    manager( std::make_unique< io::Manager >
	     ( setupManager( this->commandLine ) ) ),
    legacy( setupLegacyDirectory( this->commandLine ) ),
    modern( setupModernDirectory( this->commandLine ) ){}

  #include "njoy21/Driver/Factory/src/callOperator.hpp"
  
};
