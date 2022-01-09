# Template definitions in C++ files

## How to build
* Checkout and build
```
git clone https://github.com/f-squirrel/template_definition_in_cpp_file.git
cd template_definition_in_cpp_file
mkdir build && cd build
make
```

## How to check template instantiations
* Check instantions with `nm -C`
```
nm -C CMakeFiles/a.out.dir/use.cpp.o |grep Template
nm -C CMakeFiles/a.out.dir/main.cpp.o |grep Template
nm -C CMakeFiles/a.out.dir/template.cpp.o |grep Template
```

* Output
    - use.cpp:
    ```
    0000000000000000 W Templated<int>::Templated(int)
    0000000000000000 W Templated<int>::Templated(int)
    0000000000000000 n Templated<int>::Templated(int)
    0000000000000000 W Templated<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Templated(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
    0000000000000000 W Templated<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Templated(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
    0000000000000000 n Templated<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Templated(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
    0000000000000000 W Templated<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::~Templated()
    0000000000000000 W Templated<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::~Templated()
    0000000000000000 n Templated<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::~Templated()
                     U Templated<int>::get() const
                     U Templated<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::get() const
    ```
    Note that `get` is marked as undefined (**U**), i.e. not generated, the same for `main.cpp`

    - template.cpp:
    ```
    0000000000000000 W Templated<int>::set(int const&)
    0000000000000000 W Templated<int>::Templated(int)
    0000000000000000 W Templated<int>::Templated(int)
    0000000000000000 n Templated<int>::Templated(int)
    0000000000000000 W Templated<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::set(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)
    0000000000000000 W Templated<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Templated(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
    0000000000000000 W Templated<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Templated(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
    0000000000000000 n Templated<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::Templated(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
    0000000000000000 W Templated<int>::get() const
    0000000000000000 W Templated<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::get() const
    ```

    As you may see, the only place where methods are generated (**W**) is `templated.cpp`, i.e. the place of instantiation.
