class Sequence : public interface::Routine::Sequence {
protected:
#include "njoy21/legacy/Sequence/routines.hpp"

  /* fields */
  std::vector< std::unique_ptr< interface::Routine > > sequence;

  Sequence( std::vector< std::unique_ptr< interface::Routine > >&& sequence ) :
    sequence( std::move(sequence) ){}
  
public:
  
  #include "njoy21/legacy/Sequence/Factory.hpp"
  
  void operator()(){ for ( auto& routine : this->sequence ){ (*routine)(); } }

};
