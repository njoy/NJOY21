namespace interface {

struct Routine {

  struct Sequence {
    virtual ~Sequence() = default;

    /*
     * Passing a JSON object is intended to give us the flexibility to pass 
     * whatever arguments we wish in the future. It is the responsibility of the 
     * underlying module to determine if they want to do anything with those 
     * arguments.

     * Perhaps this shoud be a variadic template instead of passing a genric
     * JSON object
     */
    virtual void operator()( const nlohmann::json& ) = 0;
  };

  std::string name_;
  Routine( const std::string& name ):
    name_( name )
  {}

  virtual ~Routine() = default;
  virtual void operator()( std::ostream&, std::ostream&, 
                           const nlohmann::json& ) = 0;
  const std::string name() const { return this->name_; }
};

}
