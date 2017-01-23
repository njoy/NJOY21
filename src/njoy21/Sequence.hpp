namespace interface {

struct Routine {

  struct Sequence {
    virtual ~Sequence() = default;
    virtual void operator()() = 0;
  };

  virtual ~Routine() = default;
  virtual void operator()() = 0;
};

}

namespace legacy {

struct Sequence : public interface::Routine::Sequence {
protected: 

#define DEFINE_ROUTINE( MODULE )                                               \
  struct MODULE : public interface::Routine {                                  \
    template< typename Char >                                                  \
    MODULE( iRecordStream< Char >& input ){ input::MODULE commands( input ); } \
    void operator()(){ ::MODULE(); }                                           \
  };

  DEFINE_ROUTINE( MODER )
  DEFINE_ROUTINE( RECONR )
  DEFINE_ROUTINE( BROADR )
  DEFINE_ROUTINE( GASPR )
  DEFINE_ROUTINE( UNRESR )
  DEFINE_ROUTINE( PURR )
  DEFINE_ROUTINE( ACER )
#define DEFINE_ROUTINE

  std::vector< std::unique_ptr< interface::Routine > > sequence;
  Sequence( std::vector< std::unique_ptr< interface::Routine > >&& sequence ) :
    sequence( std::move(sequence) ){}
  
public:
  struct Factory {
  protected:
    
    template< typename Char>
    using parser =
      std::function
      < std::unique_ptr< interface::Routine >( iRecordStream< Char >& ) >;

    std::unordered_set< std::string >& permittedRoutines;
    
    template< typename Char >
    std::unique_ptr< interface::Routine >
    parse( std::string& label, iRecordStream< Char >& input ){
      static const std::unordered_map< std::string, parser<Char> > parserMap
      { std::make_pair< std::string, parser >
	  ( "MODER",
	    []( auto& inputStream )
	    { return std::make_unique< MODER >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "RECONR",
	    []( auto& inputStream )
	    { return std::make_unique< RECONR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "BROADR",
	    []( auto& inputStream )
	    { return std::make_unique< BROADR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "GASPR",
	    []( auto& inputStream )
	    { return std::make_unique< GASPR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "UNRESR",
	    []( auto& inputStream )
	    { return std::make_unique< UNRESR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "PURR",
	    []( auto& inputStream )
	    { return std::make_unique< PURR >( inputStream ); } ) };
      return parserMap[label]( input );      
    }
    
  public:
    Factory( std::unordered_set< std::string >& permittedRoutines ) :
      permittedRoutines( permittedRoutines ) {}

    template< typename Char >
    std::unique_ptr< interface::Routine::Sequence >
    operator()( std::string& label, iRecordStream< Char >& input ){
    }
  };

  
};
