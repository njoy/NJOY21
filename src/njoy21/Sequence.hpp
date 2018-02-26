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
  DEFINE_ROUTINE( PURR )
  DEFINE_ROUTINE( UNRESR )
  DEFINE_ROUTINE( ACER )
  DEFINE_ROUTINE( GASPR )
  DEFINE_ROUTINE( HEATR )
  DEFINE_ROUTINE( GROUPR )
  DEFINE_ROUTINE( VIEWR )
  DEFINE_ROUTINE( MIXR )
  DEFINE_ROUTINE( DTFR )
  DEFINE_ROUTINE( THERMR )
  DEFINE_ROUTINE( LEAPR )
  DEFINE_ROUTINE( RESXSR )
  DEFINE_ROUTINE( MATXSR )
  DEFINE_ROUTINE( GAMINR )
  DEFINE_ROUTINE( PLOTR )
  DEFINE_ROUTINE( COVR )
  DEFINE_ROUTINE( WIMSR )
  DEFINE_ROUTINE( POWR )
  DEFINE_ROUTINE( CCCCR )
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
	  ( "PURR",
	    []( auto& inputStream )
	    { return std::make_unique< PURR >( inputStream ); } ) };
	std::make_pair< std::string, parser >
	  ( "UNRESR",
	    []( auto& inputStream )
	    { return std::make_unique< UNRESR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "ACER",
	    []( auto& inputStream )
	    { return std::make_unique< ACER >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "GASPR",
	    []( auto& inputStream )
	    { return std::make_unique< GASPR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "HEATR",
	    []( auto& inputStream )
	    { return std::make_unique< HEATR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "GROUPR",
	    []( auto& inputStream )
	    { return std::make_unique< GROUPR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "VIEWR",
	    []( auto& inputStream )
	    { return std::make_unique< VIEWR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "MIXR",
	    []( auto& inputStream )
	    { return std::make_unique< MIXR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "DTFR",
	    []( auto& inputStream )
	    { return std::make_unique< DTFR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "THERMR",
	    []( auto& inputStream )
	    { return std::make_unique< THERMR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "LEAPR",
	    []( auto& inputStream )
	    { return std::make_unique< LEAPR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "RESXSR",
	    []( auto& inputStream )
	    { return std::make_unique< RESXSR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "MATXSR",
	    []( auto& inputStream )
	    { return std::make_unique< MATXSR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "GAMINR",
	    []( auto& inputStream )
	    { return std::make_unique< GAMINR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "PLOTR",
	    []( auto& inputStream )
	    { return std::make_unique< PLOTR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "COVR",
	    []( auto& inputStream )
	    { return std::make_unique< COVR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "WIMSR",
	    []( auto& inputStream )
	    { return std::make_unique< WIMSR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "POWR",
	    []( auto& inputStream )
	    { return std::make_unique< POWR >( inputStream ); } ),
	std::make_pair< std::string, parser >
	  ( "CCCCR",
	    []( auto& inputStream )
	    { return std::make_unique< CCCCR >( inputStream ); } ),
	std::make_pair< std::string, parser >
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
