# Cereal lib for c++ data Serialization

## docs
- [main link](https://uscilab.github.io/cereal) 

## Versioning
If you have strings in your data, import this header `#include <cereal/types/string.hpp>`

- use this macro for defining version 
  `CEREAL_CLASS_VERSION`
- [This link](https://uscilab.github.io/cereal/serialization_functions.html#versioning) 

This parameter will always be given the appropriate version number by cereal. When saving data, cereal looks for an explicit version which you can specify with the `CEREAL_CLASS_VERSION` macro (see the doxygen docs for detailed information). This macro takes a type and a version number, and causes cereal to serialize this version information when it saves that type using a versioned serialization function. If you use this macro but do not use a versioned serialization function, no version information will be saved. If you use a versioned serialization function and do not specify the version number using the macro, cereal will default to giving a version number of zero.
cereal supports adding explicit versioning information for types, much like Boost class versioning. This is optional in cereal and by default is not used for any type. You can choose to use versioning by adding an additional parameter to your serialization functions (regardless of which serialization style you are using), a const std::uint32_t, typically named version.

This parameter will always be given the appropriate version number by cereal. When saving data, cereal looks for an explicit version which you can specify with the `CEREAL_CLASS_VERSION` macro (see the doxygen docs for detailed information). This macro takes a type and a version number, and causes cereal to serialize this version information when it saves that type using a versioned serialization function. If you use this macro but do not use a versioned serialization function, no version information will be saved. If you use a versioned serialization function and do not specify the version number using the macro, cereal will default to giving a version number of zero.
