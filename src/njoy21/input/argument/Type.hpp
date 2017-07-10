template< bool >
struct defaultField{
  bool defaulted;
  defaultField( bool defaulted ) : defaulted(defaulted){}

  defaultField(){}
};

template<>
struct defaultField< false >{
  defaultField( bool ){}

  defaultField(){}
};

template< typename Policy >
struct Type : public defaultField< policy::hasDefault< Policy > > {
  using Value_t = typename Policy::Value_t;
  Value_t value;

  Type( Value_t&& value, bool success ) :
    defaultField< policy::hasDefault< Policy > >( success ),
    value( std::move(value) ){}

  template< bool defaultable = std::is_default_constructible<Value_t>::value,
	    std::enable_if_t<defaultable, int> = 0 >
  Type() : defaultField< policy::hasDefault< Policy > >() {}
};
