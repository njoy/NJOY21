#define DEFINE_ROUTINE( MODULE )                                               \
  struct MODULE : public interface::Routine {                                  \
    nlohmann::json j##MODULE;                                                  \
                                                                               \
    MODULE( lipservice::iRecordStream< char >& stream ):                       \
      interface::Routine( #MODULE )                                            \
    {                                                                          \
      lipservice::MODULE command( stream );                                    \
      this->j##MODULE = command;                                               \
    }                                                                          \
    void operator()( std::ostream& output,                                     \
                     std::ostream& error,                                      \
                     const nlohmann::json& args ){                             \
      try {                                                                    \
        njoy::MODULE::MODULE{}( std::move( this->j##MODULE ),                  \
                                output, error,                                 \
                                args );                                        \
      } catch( std::exception& e ){                                            \
        Log::info( "Trouble running modern routine: {}", #MODULE );            \
        Log::info( "{}", e.what() );                                           \
        throw e;                                                               \
      }                                                                        \
    }                                                                          \
  };                                                                           

  DEFINE_ROUTINE( RECONR )                                                      
  DEFINE_ROUTINE( LEAPR )
#undef DEFINE_ROUTINE
