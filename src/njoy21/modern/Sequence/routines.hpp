#define DEFINE_ROUTINE( MODULE )                                               \
  struct MODULE : public interface::Routine {                                  \
    nlohmann::json j##MODULE;                                                  \
                                                                               \
    template< typename Char >                                                  \
    MODULE( lipservice::iRecordStream< Char >& stream ){                       \
      lipservice::MODULE command( stream );                                    \
      this->j##MODULE = command;                                               \
    }                                                                          \
    void operator()(){                                                         \
      njoy::MODULE::MODULE{ this->j##MODULE };                                       \
    }                                                                          \
  };

  DEFINE_ROUTINE( RECONR )                                                      
#undef DEFINE_ROUTINE
