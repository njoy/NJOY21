template< typename Policy, bool, bool >
struct Composition;

template< typename Policy >
struct Composition< Policy, false, false >{
  using type = Required< Base< typename Policy::Value_t > >;
};

template< typename Policy >
struct Composition< Policy, false, true >{ 
  using type = Discriminating
               < Required< Base< typename Policy::Value_t > >, Policy >;
};

template< typename Policy >
struct Composition< Policy, true, false >{
  using type = Defaulted< Base< typename Policy::Value_t >, Policy >;
};

template< typename Policy >
struct Composition< Policy, true, true >{
  using type = 
    Defaulted
    < Discriminating
      < Optional
        < Base
	  < typename Policy::Value_t > >, Policy > >;
};
