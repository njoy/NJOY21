#define DEFINE_ROUTINE( MODULE )                                               \
  struct MODULE : public interface::Routine {                                  \
    template< typename Char >                                                  \
    MODULE( input::iRecordStream< Char >& input ){                             \
      input::MODULE commands( input );                                         \
    }									       \
    void operator()(){ njoy_c_##MODULE(); }                                    \
  };

  DEFINE_ROUTINE( MODER )
  DEFINE_ROUTINE( RECONR )
  DEFINE_ROUTINE( BROADR )
  // DEFINE_ROUTINE( GASPR )
  // DEFINE_ROUTINE( UNRESR )
  // DEFINE_ROUTINE( PURR )
  // DEFINE_ROUTINE( ACER )
#undef DEFINE_ROUTINE
