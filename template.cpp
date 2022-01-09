#include "template.h"

#include <string>

template<typename T>
const T& Templated<T>::get() const {
    return v;
}

template<typename T>
void Templated<T>::set(const T& t) {
    v = t;
}

template struct Templated<int>;
template struct Templated<std::string>;
