#include <iostream>
#include "Slide.h"

int main() {
    document::Slide ob{5};
    const auto iter = ob.getIteratorOn(2);
    *iter = 12;

    document::Slide ob2(ob);
    
    std::cout << *ob2.getIteratorOn(2) << "\n";
    return 0;
}