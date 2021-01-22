class Driver {
  using Queue = std::queue< std::unique_ptr< interface::Routine::Sequence > >;

  std::unique_ptr< io::Manager > manager;
  Queue queue;
  nlohmann::json args;

  Driver( std::unique_ptr< io::Manager >&& manager, 
          Queue&& queue, 
          nlohmann::json&& args ) :
    manager( std::move(manager) ),
    queue( std::move(queue) ),
    args( std::move( args ) )
  {}

  #include "njoy21/Driver/Factory.hpp"
  
public:
  Driver( int argc, char* argv[] ) :
    Driver( Factory( argc, argv )() ){}

  #include "njoy21/Driver/src/callOperator.hpp"
};
