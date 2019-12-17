template< typename T >
static void ignore( T&& ){}

#define DEFINE_ROUTINE( MODULE )					\
  struct MODULE : public interface::Routine {                                  \
    template< typename Char >                                                  \
    MODULE( lipservice::iRecordStream< Char >& stream ){                       \
      lipservice::MODULE command( stream );                                    \
      ignore(command);                                                         \
    }									                                                         \
    void operator()(){ Log::info( "In modern MODULE module." ); }              \
  };

  DEFINE_ROUTINE( RECONR )
#undef DEFINE_ROUTINE
