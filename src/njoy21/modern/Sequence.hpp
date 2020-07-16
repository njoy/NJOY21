class Sequence : public interface::Routine::Sequence {
protected:
#include "njoy21/modern/Sequence/routines.hpp"

  using List = std::vector< std::unique_ptr< interface::Routine > >;
  
  /* fields */
  io::Manager& manager;
  List sequence;
  std::chrono::steady_clock::time_point begin_;

  Sequence( io::Manager& manager, List&& sequence ) :
    manager( manager ), 
    sequence( std::move( sequence ) ),
    begin_( std::chrono::steady_clock::now() )
  {}
  
public:
  
  #include "njoy21/modern/Sequence/Factory.hpp"
  
  void operator()( const nlohmann::json& args ){
    auto fileGuard = manager.output( this );

    auto& output = *fileGuard.first;

    for ( auto& routine : this->sequence ){ 
      (*routine)( *fileGuard.first, *fileGuard.second, args ); 

      auto timeDiff = std::chrono::duration_cast< std::chrono::microseconds >(
        std::chrono::steady_clock::now() - begin_ ).count();

      output << fmt::format( "{}... {:70.3f} s", routine->name(), timeDiff )
             << std::endl;
    }
  }
};
