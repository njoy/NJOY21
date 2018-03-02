template< typename T >
static void ignore( T&& ){}

#define DEFINE_ROUTINE( MODULE )					\
  struct MODULE : public interface::Routine {                                  \
    template< typename Char >                                                  \
    MODULE( input::iRecordStream< Char >& stream ){                            \
      input::MODULE command( stream );                                         \
      ignore(command);                                                         \
    }									       \
    void operator()(){ njoy_c_##MODULE(); }                                    \
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
