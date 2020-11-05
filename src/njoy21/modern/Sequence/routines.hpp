#define DEFINE_ROUTINE( MODULE )                                               \
  struct MODULE : public interface::Routine {                                  \
    nlohmann::json j##MODULE;                                                  \
                                                                               \
    template< typename Char >                                                  \
    MODULE( lipservice::iRecordStream< Char >& stream ):                       \
      interface::Routine( #MODULE )                                            \
    {                                                                          \
      lipservice::MODULE command( stream );                                    \
      this->j##MODULE = command;                                               \
    }                                                                          \
    void operator()( std::ostream& output,                                     \
                     std::ostream& error,                                      \
                     const nlohmann::json& args ){                             \
      njoy::MODULE::MODULE{}( std::move( this->j##MODULE ),                    \
                              output, error,                                   \
                              args );                                          \
    }                                                                          \
    virtual std::string name(){ return #MODULE; }                              \
  };                                                                           

  //DEFINE_ROUTINE( RECONR )                                                      
  DEFINE_ROUTINE( LEAPR )                                                      
#undef DEFINE_ROUTINE
