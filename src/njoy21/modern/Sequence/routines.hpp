#define DEFINE_ROUTINE( MODULE )                                               \
  struct MODULE : public interface::Routine {                                  \
    nlohmann::json j##MODULE;                                                  \
                                                                               \
    template< typename Char >                                                  \
    MODULE( lipservice::iRecordStream< Char >& stream ){                       \
      lipservice::MODULE command( stream );                                    \
      this->j##MODULE = command;                                               \
    }                                                                          \
    void operator()( std::ostream& output, const nlohmann::json& args ){       \
      njoy::MODULE::MODULE{}( std::move( this->j##MODULE ),                    \
                              output,                                          \
                              args );                                          \
    }                                                                          \
  };

  DEFINE_ROUTINE( RECONR )                                                      
#undef DEFINE_ROUTINE
