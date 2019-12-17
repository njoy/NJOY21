template< typename T >
static void ignore( T&& ){}

#define DEFINE_ROUTINE( MODULE )					\
  struct MODULE : public interface::Routine {                                  \
    nlohmann::json jMODULE;                                                    \
                                                                               \
    template< typename Char >                                                  \
    MODULE( lipservice::iRecordStream< Char >& stream ){                       \
      this->jMODULE = lipservice::MODULE{ stream };                            \
    }									                                                         \
    void operator()(){                                                         \
      Log::info( "In modern MODULE module." );                                 \
      Log::info( "JSON representation:\n{}", this->jMODULE );                  \

      // MODULE();
    }                                                                          \
  };

  DEFINE_ROUTINE( RECONR )
#undef DEFINE_ROUTINE
