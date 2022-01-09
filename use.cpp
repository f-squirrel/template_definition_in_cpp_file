#include "template.h"
#include <iostream>
#include <string>

void use() {
    Templated<int> t{1};
    std::cout << t.get() << std::endl;

    Templated<std::string> t1{"use"};
    std::cout << t1.get() << std::endl;
}
