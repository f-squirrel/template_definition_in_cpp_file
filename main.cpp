#include "template.h"
#include "use.h"
#include <iostream>

int main() {
    Templated<int> t{1};
    std::cout << t.get() << std::endl;

    Templated<std::string> t1{"use"};
    std::cout << t1.get() << std::endl;

    use();
    return 0;
}
