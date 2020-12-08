struct Factory {
protected:
    
  using parser = std::function < 
    std::unique_ptr< interface::Routine >(
      lipservice::iRecordStream< char >& ) >;

  io::Manager& manager;
  std::unordered_set< std::string >& permittedRoutines;

  #include "njoy21/legacy/Sequence/Factory/src/parse.hpp"
    
public:
  Factory( io::Manager& manager,
	   std::unordered_set< std::string >& permittedRoutines ) :
    manager( manager ),
    permittedRoutines( permittedRoutines ){}

  #include "njoy21/legacy/Sequence/Factory/src/callOperator.hpp"
};  
