template< typename T >
static void ignore( T&& ){}

#define DEFINE_ROUTINE( MODULE )					                                     \
  struct MODULE : public interface::Routine {                                  \
    using Stream = lipservice::iRecordStream< char >;                          \
    int offset;                                                           \
    MODULE( lipservice::iRecordStream< char >& stream ):                       \
      interface::Routine( #MODULE )                                            \
    {                                                                          \
      offset = stream.tellg();                                                 \
      Log::info( "{} offset before: {}", this->name(), offset );               \
      lipservice::MODULE command( stream );                                    \
      Log::info( "{} offset after: {}", this->name(), stream.tellg() );        \
      ignore(command);                                                         \
    }									                                                         \
    void operator()( std::ostream&, std::ostream&, const nlohmann::json& ){    \
      try {                                                                    \
        Log::info( "() offset: {}", offset ); \
        njoy_set_input_offset( offset );                                   \
        njoy_c_##MODULE();                                                     \
      } catch( std::exception& e ){                                            \
        Log::info( "Trouble running legacy routine: {}", #MODULE );            \
        Log::info( "{}", e.what() );                                           \
        throw e;                                                               \
      }                                                                        \
    }                                                                          \
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
  DEFINE_ROUTINE( ERRORR )
#undef DEFINE_ROUTINE
