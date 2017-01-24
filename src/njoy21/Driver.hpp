class Driver {
  using Queue =
    std::queue< std::unique_ptr< interface::Routine::Sequence > >;

  std::unique_ptr< io::Manager > manager;
  Queue queue;

  Driver( std::unique_ptr< io::Manager >&& manager, Queue&& queue ) :
    manager( std::move(manager) ),
    queue( std::move(queue) ){}

  #include "njoy21/Driver/Factory.hpp"
  
public:
  Driver( int argc, char* argv[] ) :
    Driver( Factory( argc, argv )() ){}

  void operator()(){
    while ( this->queue.size() ){
      auto& routine = *( this->queue.front() );
      routine();
      this->queue.pop();
    }
  }
};
