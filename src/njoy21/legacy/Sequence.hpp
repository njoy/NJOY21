class Sequence : public interface::Routine::Sequence {
protected:
#include "njoy21/legacy/Sequence/routines.hpp"

  using List = std::vector< std::unique_ptr< interface::Routine > >;
  
  /* fields */
  io::Manager& manager;
  List sequence;

  Sequence( io::Manager& manager, List&& sequence ) :
    manager( manager ), sequence( std::move(sequence) ){}
  
public:
  
  #include "njoy21/legacy/Sequence/Factory.hpp"
  
  void operator()(){
    auto fileGaurd = manager.output( this );
    for ( auto& routine : this->sequence ){ (*routine)(); }
  }

};
